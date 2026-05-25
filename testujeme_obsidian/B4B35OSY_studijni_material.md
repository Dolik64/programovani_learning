# Operační systémy (B4B35OSY) — souvislý studijní materiál

Tento text pokrývá všech sedm tematických okruhů ke státnicím / zkoušce. Je psaný tak, aby se z něj dalo učit od začátku do konce — každá kapitola navazuje na předchozí, terminologie se zavádí postupně a u každého konceptu je vysvětlené **proč** to tak je, ne jen jak to vypadá.

---

## Úvodní zarámování

Operační systém je vrstva mezi hardwarem a aplikacemi. Plní tři velké úkoly:

1. **Abstrakce hardwaru** — aplikace nepíšou „pošli bajt na port řadiče disku", ale zavolají `read()`. OS schová, jaký disk je pod tím.
2. **Správa zdrojů** — CPU, RAM, disk, síť sdílí desítky procesů. OS rozhoduje, kdo kdy a kolik dostane.
3. **Izolace a ochrana** — chyba (nebo útok) v jedné aplikaci nesmí položit zbytek systému.

Všechny tři úkoly se prolínají do každého z následujících témat. Systémová volání jsou nástroj abstrakce, plánovač procesů je správa zdrojů, virtuální paměť dělá obojí najednou.

---

## 1. Systémová volání

### Proč existují

Aplikace běží v **uživatelském režimu** (na x86 *ring 3*), kde nemá přímý přístup k hardwaru ani k paměti jádra. Pokud chce pracovat se souborem, sítí nebo vytvořit proces, musí požádat jádro. Systémové volání je **kontrolovaný přechod** z uživatelského do jádrového režimu (ring 0).

> **Pozn.:** Intel v r. 2024 oznámil útlum ringů 1 a 2, protože je moderní OS nevyužívají — reálně se používá jen ring 0 a ring 3.

### Jak se volání technicky provede

V kódu napíšeš `read(fd, buf, n)` — to je obyčejná funkce z libc. Uvnitř se ale děje toto:

1. Číslo systémového volání (každý syscall má své — `read` je třeba 0 na x86-64 Linuxu) se uloží do registru `rax`.
2. Argumenty se uloží do dalších registrů. Konvence v Linuxu na x86-64: `rdi, rsi, rdx, r10, r8, r9` (v tomto pořadí, prvních 6 argumentů).
3. Vykoná se speciální instrukce **SYSCALL** (dříve `int 0x80` nebo `SYSENTER`), která:
   - přepne CPU do ring 0,
   - skočí na předem nastavený vstupní bod jádra (registr `MSR_LSTAR`).
4. Jádro provede operaci, výsledek uloží do `rax`. Záporná hodnota = chyba (`-EINVAL`, `-EPERM`, ...).
5. Instrukce **SYSRET** vrátí CPU zpět do ring 3 a do uživatelského kódu.

Tomu, co definuje, **které číslo je který syscall, jak se předávají argumenty a kam jde návratová hodnota**, se říká **ABI (Application Binary Interface)**. ABI je závazek: kdyby se změnilo, přestaly by fungovat všechny zkompilované binárky.

### Jak se předávají velká data

Do registru se vejde nejvýš ukazatel. Pokud tedy aplikace chce předat strukturu nebo buffer, předá **ukazatel na uživatelskou paměť**. Jádro nemůže ukazateli důvěřovat — uživatel mohl předat ukazatel do jádrové paměti! Proto jádro každé takové dereferenci validuje (kontroluje, že adresa leží v adresním prostoru procesu a má správná oprávnění). V Linuxu jsou pro to funkce `copy_from_user()` a `copy_to_user()`.

### Ochrana paměti jádra

Spočívá ve dvou pilířích, které spolu fungují:

- **Privilegované režimy CPU** — uživatelský kód v ring 3 prostě nemá oprávnění vykonat instrukce, které čtou nebo zapisují do jádrové paměti. Pokus skončí výjimkou (segfault).
- **Virtuální paměť** — každý proces má vlastní stránkovací tabulku. Stránky patřící jádru mají v záznamu příznak „supervisor only". I kdyby uživatelský kód znal jejich virtuální adresu, MMU překlad nedovolí.

Tyto dvě věci dohromady zajišťují, že jediná cesta z uživatelského kódu do jádra vede přes řízený vstupní bod — instrukci SYSCALL. Žádná jiná cesta neexistuje.

### Mikrojádro vs. monolitické jádro

Toto je **filosofická volba**, jak rozhodnout, co poběží v ring 0 a co v ring 3.

**Monolitické jádro** (Linux, většina BSD) vrazí do ring 0 prakticky vše: plánovač, správu paměti, ovladače, síťový stack, souborové systémy. Komponenty mezi sebou komunikují přímými voláními funkcí — rychle, žádná režie. Cena: chyba v ovladači (nebo bezpečnostní díra) může položit nebo kompromitovat celý systém. Velikost kódu jádra Linuxu je v milionech řádků.

**Mikrojádro** (MINIX, QNX, L4) v ring 0 nechá jenom úplné minimum — IPC, plánování, základní správu paměti. Ovladače, souborové systémy a další služby běží jako obyčejné procesy v ring 3 a komunikují s jádrem a mezi sebou přes IPC (zprávy). Výhoda: pád ovladače tiskárny neshodí systém, lze ho restartovat. Nevýhoda: každá interakce mezi službami je IPC = přepnutí kontextu = pomalejší.

**Hybridní jádro** (Windows NT, macOS XNU) kombinuje obojí — strukturováno jako mikrojádro, ale klíčové komponenty kvůli výkonu zůstávají v ring 0.

| Kritérium | Monolitické | Mikrojádro |
|---|---|---|
| Výkon | vysoký (přímá volání) | nižší (IPC overhead) |
| Modularita | nízká | vysoká |
| Stabilita | pád = celý systém | pád služby = restart služby |
| Velikost ring 0 | velká | malá |
| Bezpečnost | větší attack surface | menší attack surface |

---

## 2. Procesy a vlákna

### Proces

**Proces** je instance běžícího programu. Není to soubor na disku — to je **program**. Proces je objekt spravovaný jádrem, který má:

- vlastní **virtuální adresní prostor** (s oblastmi `.text` pro kód, `.data` pro globální proměnné, `.stack`, **heap** pro dynamickou alokaci),
- otevřené **deskriptory souborů**, sokety, roury,
- bezpečnostní kontext (UID, GID, capabilities),
- jedinečný **PID**,
- alespoň jedno vlákno (jinak by neměl co vykonávat).

V jádře je proces reprezentován strukturou **PCB (Process Control Block)**. Ta obsahuje PID, stav procesu, ukazatel na stránkovací tabulky (= adresní prostor), seznam otevřených souborů, signálovou masku, limity zdrojů, statistiky CPU času atd.

### Vlákno

**Vlákno** je sekvence instrukcí, kterou plánovač přiděluje na CPU. Více vláken jednoho procesu **sdílí adresní prostor** — tj. tutéž paměť, tytéž otevřené soubory, tatáž globální data. Liší se ale v tom, co je „tady a teď" právě vykonáváno.

Co má každé vlákno **vlastní**:
- registry CPU (včetně `PC` — programového čítače a `SP` — ukazatele zásobníku),
- vlastní zásobník (pro lokální proměnné a návratové adresy volání funkcí),
- **TLS (Thread-Local Storage)** — proměnné, které vypadají jako globální, ale každé vlákno má vlastní instanci (např. `errno`).

V jádře je vlákno reprezentováno **TCB (Thread Control Block)**. PCB udržuje seznam všech TCB patřících procesu.

### Co sdílejí vlákna jednoho procesu — přehled

Toto je častá zkoušková otázka. Klíč: vše, co je v adresním prostoru procesu, je sdílené; vše, co je v kontextu CPU nebo na zásobníku konkrétního vlákna, je privátní.

| Položka | Sdílené mezi vlákny? | Privátní pro vlákno? |
|---|:---:|:---:|
| Kód (`.text`) | ✔ | |
| Globální a statické proměnné (`.data`, `.bss`) | ✔ | |
| Heap (dynamicky alokovaná paměť, `malloc`) | ✔ | |
| Otevřené soubory, sokety | ✔ | |
| Programový čítač (PC) | | ✔ |
| Registry CPU | | ✔ |
| Zásobník (lokální proměnné, návratové adresy) | | ✔ |
| Thread-Local Storage (TLS) | | ✔ |

> Pozor na detail: **dynamicky alokovaná paměť** (přes `malloc`) leží na heapu, takže je **sdílená**. To, že máš ukazatel `int *p = malloc(...)` v lokální proměnné jednoho vlákna, neznamená, že je paměť privátní — ostatní vlákna se k ní můžou dostat, pokud jim ukazatel předáš.

### Vytváření procesu — `fork()` a `exec()`

V UNIXu se nový proces tvoří voláním `fork()`. To vytvoří **téměř identickou kopii** rodičovského procesu:

- nový PID,
- kopie adresního prostoru (ve skutečnosti přes copy-on-write — viz kapitola 4),
- kopie tabulky deskriptorů,
- návratová hodnota se liší: rodič dostane PID dítěte, dítě dostane 0.

```c
pid_t pid = fork();
if (pid == 0) {
    // jsem dítě
    execvp("/bin/ls", args);  // nahradí svůj kód programem ls
} else {
    // jsem rodič, čekám na dítě
    waitpid(pid, &status, 0);
}
```

`exec()` přepíše obsah procesu jiným programem (nahradí `.text`, `.data`, vyresetuje stack a heap). PID se nemění. Takhle se v UNIXu spouští nové programy: rodič udělá `fork`, potomek udělá `exec`.

### Předávání dat mezi procesy (IPC)

Procesy mají oddělené adresní prostory, takže si jen tak nepředají ukazatel. Možností je několik:

| Mechanismus | Vlastnosti |
|---|---|
| **Roura (pipe)** | jednosměrný stream bytů, jen mezi příbuznými procesy |
| **Pojmenovaná roura (FIFO)** | jako pipe, ale identifikovaná názvem v souborovém systému |
| **Sdílená paměť** (`shm_open`, `mmap`) | nejrychlejší — segment paměti namapovaný do více procesů; vyžaduje vlastní synchronizaci |
| **Soubor mapovaný do paměti** | varianta sdílené paměti přes soubor |
| **Sokety** | obousměrná komunikace, funguje i přes síť |
| **Zasílání zpráv** (např. POSIX message queues) | strukturované zprávy s prioritami |
| **Signály** | jednoduchá asynchronní notifikace (např. `SIGTERM`); nepředávají data, jen říkají „něco se stalo" |
| **Soubor** | nejprimitivnější — jeden zapíše, druhý čte |

### Stavy procesu (a vlákna)

```
   [Nový] → [Připravený] ⇄ [Běžící] → [Ukončený]
                  ↑           ↓
                  └─[Čekající]┘
```

- **Nový** — proces se právě vytváří.
- **Připravený (Ready)** — má vše potřebné, čeká jen na CPU.
- **Běžící (Running)** — právě vykonává instrukce.
- **Čekající / Blokovaný** — čeká na událost (I/O, signál, semafor).
- **Ukončený** — proces skončil, ale ještě může čekat, než si rodič vyzvedne návratovou hodnotu (zombie).

Přepnutí mezi stavy nastává po přerušení (interrupt), výjimce nebo když proces sám něco řekne jádru (syscall).

### PCB vs. TCB — proč na tom záleží

Přepnutí mezi vlákny stejného procesu mění **jen TCB** — registry, SP, PC. Adresní prostor zůstává, takže se nemusí flushovat TLB ani přepínat stránkovací tabulky. Je to rychlé.

Přepnutí mezi procesy je **dražší** — kromě registrů se mění CR3 (ukazatel na stránkovací tabulky), invalidují se TLB záznamy (pokud se nepoužije ASID/PCID), může docházet k cache miss. Proto je vícevláknové programování často efektivnější než vícepocesové, pokud je úloha vhodná.

---

## 3. Synchronizace vláken

Jakmile máš víc vláken, která sdílí data, vznikají problémy. Cílem synchronizace je zajistit, aby vlákna v daný okamžik nepřistupovala ke sdíleným datům způsobem, který by porušil **invarianty** programu.

### Tři problémy paralelního přístupu

**Data race** — výsledek závisí na tom, v jakém pořadí vlákna provedou své instrukce. Klasika:

```c
counter++;  // toto NENÍ atomické!
// ve skutečnosti: load counter, add 1, store counter
```

Když dvě vlákna provádí `counter++` současně, můžou obě načíst stejnou hodnotu, obě k ní přičíst 1 a uložit — výsledek je o 1 menší než má být. Race condition.

**Deadlock** — skupina vláken se navzájem blokuje, nikdo nemůže pokračovat. Detail níže.

**False sharing** — výkonnostní (ne korektnostní) problém. Cache line má typicky 64 B. Když dvě vlákna pracují s různými proměnnými, které ale leží na stejné cache line, procesory si tu cache line neustále přebírají mezi jádry (cache coherency protokol). Korektnost zachována, výkon v háji.

### Kritická sekce

**Kritická sekce** je úsek kódu, kde se sahá na sdílená data a musí se vykonat „bez rušení". Hlavní úkol synchronizačních primitiv: zajistit, aby v kritické sekci bylo v daný okamžik nejvýš jedno vlákno (vzájemné vyloučení, *mutual exclusion*).

### Synchronizační primitiva

#### Mutex (mutual exclusion lock)

Zámek se dvěma stavy: zamčený / odemčený. `lock()` zámek vezme (nebo počká, je-li držen). `unlock()` ho uvolní. Vlákno, které volá `unlock`, by mělo být totéž, co zavolalo `lock` — vlastnictví je vázané na vlákno.

```c
pthread_mutex_lock(&m);
counter++;  // kritická sekce
pthread_mutex_unlock(&m);
```

Mutex čekající vlákno **uspí** (jádro ho vyřadí ze scheduleru, dokud ho neprobudí).

#### Semafor

Celočíselný čítač s atomickými operacemi:

- `wait(sem)` (P, down) — pokud `sem > 0`, dekrementuje a pokračuje. Pokud `sem == 0`, vlákno se uspí.
- `signal(sem)` (V, up) — inkrementuje `sem`, případně probudí čekající vlákno.

Binární semafor (hodnoty 0/1) se dá použít jako mutex. Ale obecný semafor zvládá víc — třeba „dovol nejvýš N vláken najednou" (pool zdrojů).

**Klíčový rozdíl proti mutexu:** semafor není vázán na vlastnictví. Vlákno A může udělat `wait`, vlákno B udělá `signal`. To se hodí pro signalizaci mezi vlákny.

#### Podmínkové proměnné (condition variables)

Slouží k čekání na **stav** sdílených dat — typicky „fronta není prázdná", „buffer má místo", „dokumentu se zpracoval".

Princip: vlákno drží mutex, otestuje predikát. Pokud neplatí, zavolá `cond_wait(&cond, &mutex)`, což **atomicky** uvolní mutex a uspí vlákno. Když jiné vlákno změní stav, zavolá `cond_signal(&cond)` (probudí jedno) nebo `cond_broadcast(&cond)` (probudí všechna). Probuzené vlákno se snaží znovu zamknout mutex, a teprve pak pokračuje.

```c
pthread_mutex_lock(&m);
while (queue_empty)                  // POZOR: while, ne if!
    pthread_cond_wait(&cond, &m);    // atomicky uvolní m + uspí; po probuzení znovu zamkne m
dequeue_item();
pthread_mutex_unlock(&m);
```

**Spurious wake-ups:** vlákno se může probudit i bez signálu (důsledek implementace v jádře). Proto se predikát musí testovat ve `while`, nikoli `if` — kdyby tam bylo `if`, vlákno by po falešném probuzení pokračovalo s neplatným předpokladem.

**Rozdíl od semaforu:** semafor si pamatuje historii (čítač). Když uděláš `signal` a nikdo nečeká, čítač se zvýší a další `wait` projde. Podmínková proměnná **nepamatuje nic** — pokud uděláš `signal`, když nikdo nečeká, signál se ztratí. Proto musí být predikát ve sdílené proměnné chráněné mutexem; podmínková proměnná je jen mechanismus probouzení.

#### Spin-lock

Místo uspání vlákno **aktivně točí v cyklu**, dokud se zámek neuvolní:

```asm
spin:
    mov   $1, %eax
    xchg  %eax, lock      ; ATOMICKY: zapiš 1, vrať starou hodnotu
    test  %eax, %eax
    jnz   spin            ; když byla 1, pořád obsazeno → zkus znovu
    ; tady mám zámek
```

Atomická instrukce `xchg` (test-and-set) nebo `cmpxchg` (compare-and-swap) je klíčová: hardware uzamkne cache line, takže během operace nikdo nemůže měnit obsah `lock`. Bez toho bychom měli race condition i v samotném zamykání.

**Kdy se vyplatí:**
- Velmi krátké kritické sekce (≤ ~100 cyklů). Uspání + probuzení je dražší než pár desítek cyklů spinování.
- Vícejádra, kde je šance, že držitel zámku právě běží na jiném jádře a brzy ho uvolní.
- Kontext, kde uspání není možné — interrupt handler, kernel kritické sekce.

**Kdy ne:**
- Jednojádro — vlákno spinuje, ale držitel zámku nemůže pokračovat, dokud spinující neztratí kvantum. Marný spin.
- Dlouhé kritické sekce — plýtvání CPU.

Pro férovost se používají varianty (ticket lock, MCS lock), které dávají vláknům „pořadová čísla" a zaručují FIFO pořadí.

#### Monitor

Vyšší abstrakce — třída, která zapouzdřuje sdílená data, automaticky se zamyká při vstupu do veřejné metody a odemyká při výstupu. Programátor nemůže zapomenout uvolnit zámek. V Javě to dělá klíčové slovo `synchronized`.

Vnitřně je monitor postavený nad „mutex + podmínková proměnná". Výhoda: bezpečnější a samodokumentující — kritická data jsou private a přístupná jen přes synchronizované metody.

### Deadlock

**Deadlock (uváznutí)** vzniká, když skupina vláken čeká na zdroje držené někým jiným ze skupiny tak, že nikdo nemůže pokračovat.

Klasický příklad — dvě vlákna, dva zámky, opačné pořadí:

```
Vlákno A:                  Vlákno B:
lock(zamek1);              lock(zamek2);
lock(zamek2);  ← čeká      lock(zamek1);  ← čeká
... ...
```

#### Coffmanovy podmínky

Deadlock vznikne **právě tehdy**, když jsou splněny všechny čtyři:

1. **Vzájemné vyloučení** — zdroj může současně držet jen jedno vlákno.
2. **Hold and wait** — vlákno drží zdroj a žádá další.
3. **Neodnímatelnost (no preemption)** — zdroj nelze násilně odebrat, musí ho uvolnit ten, kdo ho drží.
4. **Cyklické čekání** — existuje uzavřený cyklus v grafu „kdo čeká na koho".

Pokud kteroukoli podmínku zlomíš, deadlock nevznikne.

#### Strategie proti deadlocku

**Prevence** — strukturálně znemožnit některou z podmínek:
- Globální pořadí zámků: vždy ber zámky v rostoucím pořadí ID. Cyklus pak nevznikne.
- Hold-and-wait: ber všechny zámky najednou (pokud nelze, neber žádný).

**Vyhýbání (avoidance)** — algoritmus bankéře. Před přidělením zdroje systém ověří, zda by stav zůstal „bezpečný" (existuje nějaké pořadí, ve kterém všichni dokončí). Vyžaduje předem vědět maximální nároky každého procesu — málokdy realistické.

**Detekce + obnova** — nech deadlock vzniknout, periodicky kontroluj graf čekání, při detekci cyklu vlákno zruš nebo odeber zdroj. Drahé, používá se hlavně v databázích.

**Ignorování** („pštrosí algoritmus") — předpokládat, že se to skoro nikdy nestane. UNIX a Windows v podstatě dělají toto u běžných zámků.

---

## 4. Správa virtuální a fyzické paměti

### Proč virtuální paměť

Kdyby aplikace pracovaly přímo s fyzickými adresami, nastalo by několik problémů:
- Dva procesy by si přepisovaly paměť.
- Adresování by se měnilo podle toho, kam program zaalokoval kompilátor.
- Nedalo by se snadno chránit paměť jádra.
- Každý program by musel řešit fragmentaci sám.

Řešení: **virtuální adresní prostor (LAP)**. Každý proces vidí svou vlastní souvislou paměť od adresy 0 do velikosti adresního prostoru (32-bit: 4 GiB, 64-bit prakticky 256 TiB při 48-bitových adresách). MMU (Memory Management Unit) v CPU překládá virtuální adresy na fyzické adresy ve fyzickém adresním prostoru (FAP).

### Segmentace (historický kontext)

Starší přístup: paměť se dělila na **segmenty** různé délky (kód, data, zásobník), adresa byla `(selektor, offset)`. Selektor indexoval do segmentové tabulky, kde byla základní adresa a délka segmentu. MMU pak spočítala fyzickou adresu jako `základna + offset` a kontrolovala, že offset je v rámci segmentu.

**Výhody:** přirozené oddělení oblastí s různými právy, segmentation fault při překročení.

**Problém:** segmenty jsou různě velké → po čase vzniká **externí fragmentace** (volná paměť je rozdělená na malé kousky, do kterých se velký segment nevejde, i když volného místa je dost dohromady).

Proto moderní systémy používají stránkování. Segmentace na x86 ještě pořád existuje, ale v 64-bit režimu je v podstatě vypnutá (selektory mají základnu 0 a maximální délku).

### Stránkování (paging)

Klíčová myšlenka: rozděl jak virtuální, tak fyzickou paměť na **stejně velké bloky**.
- Virtuální blok = **stránka (page)**.
- Fyzický blok = **rámec (frame)**.
- Typická velikost: 4 KiB (existují i huge-pages 2 MiB, gigapages 1 GiB).

Mapování stránka → rámec udržuje **stránkovací tabulka** (page table). Každý proces má vlastní.

**Virtuální adresa** se skládá z:
- horní bity = **index do stránkovací tabulky** (vyber rámec),
- dolních 12 bitů (u 4 KiB stránek) = **offset uvnitř stránky**.

```
| index stránky | offset 12 bit |
        ↓
   page table
        ↓
| číslo rámce (PFN) | offset 12 bit |  ← fyzická adresa
```

**Page Table Entry (PTE)** obsahuje:
- PFN (Page Frame Number) — kam stránka ukazuje,
- bit *valid* — je stránka v RAM, nebo třeba odložená na disk?
- bity přístupových práv (R/W/X, user/supervisor),
- bit *accessed* — bylo k stránce přistupováno (pro algoritmy výběru oběti),
- bit *dirty* — bylo do stránky zapsáno (pro rozhodnutí, jestli ji při výhozu zapisovat na disk).

### Eliminace externí fragmentace

Protože všechny rámce mají stejnou velikost, libovolnou stránku lze umístit do libovolného volného rámce. **Externí fragmentace zaniká** — OS jen vede bitmapu volných rámců, výběr je O(1).

Vzniká ale **interní fragmentace**: poslední stránka procesu obvykle není plně využita. Maximální plýtvání = velikost stránky − 1 byte na proces, což je u 4 KiB stránek zanedbatelné.

### TLB (Translation Lookaside Buffer)

Naivní stránkování by každý přístup do paměti zdvojnásobilo: 1× čtení PTE z paměti + 1× samotná data. Plus u víceúrovňového stránkování ještě hůř.

Řešení: **TLB** — malá, plně asociativní cache překladů (virt → fyz) přímo v MMU. Desítky až stovky záznamů na jádro.

- **TLB hit** — překlad nalezen, jdeme rovnou na fyzickou adresu (1 takt).
- **TLB miss** — MMU musí projít stránkovací tabulky v paměti (page walk). Po nalezení se výsledek uloží do TLB.

**TLB shootdown** — když se v jednom procesu změní mapování (`mmap`, `unmap`, `fork`), všechny CPU, které ten proces používaly, musí invalidovat své TLB záznamy. Posílá se to mezi-procesorovými přerušeními (IPI). Drahé.

**ASID / PCID** — značka v TLB identifikující adresní prostor. Bez ní by se TLB musela při každém context switchi flushnout. S ní můžou v TLB koexistovat záznamy více procesů.

### Víceúrovňové stránkování

Proč ne plochá tabulka? Spočítej: 32-bit adres × 4 KiB stránky = 2²⁰ záznamů, každý 4 B = 4 MiB tabulka **per proces**. U 64-bit s 48-bit adresami už 2³⁶ záznamů × 8 B = 0,5 TiB. Naprosto neudržitelné.

**Trik:** stránkuj samotnou tabulku. Tabulky se uloží do stránek, alokují se jen ty větve stromu, které proces skutečně používá.

| Architektura | Úrovně | Dekompozice virtuální adresy |
|---|---|---|
| x86 (32-bit) | 2 (PDE → PTE) | 10 + 10 + 12 |
| x86-64 (48-bit LAP) | 4 (PML4 → PDPTE → PDE → PTE) | 9 + 9 + 9 + 9 + 12 |
| x86-64 (57-bit LAP) | 5 (PML5 → ...) | 9 × 5 + 12 |

Každá úroveň je tabulka 512 záznamů (= 9 bitů). Hloubka stromu odpovídá tomu, kolik bitů adresy se musí překládat.

Cena: TLB miss může vyžadovat **až 4 (resp. 5) čtení paměti** pro page walk. Proto na něm tolik záleží na TLB hit rate.

### Page fault — co se stane při přístupu na nepřítomnou stránku

1. CPU zjistí, že PTE má bit *valid* = 0 (nebo chybí oprávnění).
2. Vyvolá výjimku **page fault**, předá řízení jádru.
3. Jádro se podívá, co je za příčinu:
   - **Validní stránka, ale není v RAM** (např. v swapu nebo ještě neloadovaná z binárky) → najít volný rámec (případně někomu jinému stránku odebrat — viz výběr oběti), načíst data, aktualizovat PTE, vrátit se a zopakovat instrukci.
   - **Copy-on-write stránka** → alokovat novou kopii, přemapovat (viz dále).
   - **Skutečně neplatný přístup** → poslat procesu signál SIGSEGV.

### Odkládání stránek na disk (swapping)

Když dochází fyzická paměť, OS přesune nečinné stránky na disk do **swap area**. Stránka se z RAM uvolní (bit valid v PTE → 0, místo PFN se uloží pozice ve swapu). Když k ní proces zase sáhne, vyvolá se page fault a stránka se načte zpět.

**Demand paging** — stránky binárky se ani nečtou předem; načítají se až při prvním přístupu. To je důvod, proč se velké programy spouští rychle.

**Thrashing** — patologický stav, kdy je paměti tak málo, že systém většinu času swapuje, místo aby počítal. Page fault za page faultem. Řešení: víc RAM, omezit počet procesů, snížit working set.

### Algoritmy výběru oběti (page replacement)

Když potřebuju volný rámec a žádný není, koho vyhodit? Cíl: vyhodit stránku, která **nebude brzy potřeba**. Optimum (vyhodit tu, která bude potřeba nejdál v budoucnu) nelze implementovat — nevíme budoucnost. Používají se heuristiky.

| Algoritmus | Princip | Poznámka |
|---|---|---|
| **FIFO** | vyhoď nejstarší | jednoduchý, ale trpí Beladyho anomálií (víc paměti = horší výkon) |
| **Second-Chance (Clock)** | FIFO s bitem *referenced* | dá stránce „druhou šanci"; varianta v Linuxu |
| **LRU** | vyhoď nejdéle nepoužitou | přesný LRU drahý; OS používají aproximace (přes bit *accessed*) |
| **Working-Set** | drž stránky aktivní v posledním Δ času | přesnější, ale dražší výpočet |
| **ARC** (Adaptive Replacement Cache) | kombinace LRU + LFU | moderní OS, ZFS, databáze |

### Copy-on-Write (COW)

Optimalizace pro `fork()`. Naivní implementace by zkopírovala celý adresní prostor — drahé, navíc často zbytečné, protože `fork` je obvykle hned následován `exec`em (který vše stejně přepíše).

**COW trik:**
1. Po `fork` rodič i potomek **sdílejí tytéž rámce**, ale stránky jsou označené jako **read-only** (i ty, co byly zapisovatelné).
2. Když jeden z procesů zkusí zapsat, vyvolá se page fault.
3. Jádro alokuje nový rámec, **zkopíruje obsah** té jedné stránky, přemapuje ji do procesu, který zapisoval, a označí ji writable.

Výsledek: kopíruje se jen to, co se opravdu změnilo. Statická data (`.text`, sdílené knihovny) se nikdy nekopírují, sdílí se napořád.

### Shrnutí výhod a nevýhod stránkování

**Výhody:**
- Žádná externí fragmentace.
- Snadný růst heapu/zásobníku.
- Izolace procesů + sdílení (kód, knihovny).
- Virtuální paměť > fyzická (swap).
- Umožňuje COW, mmap, lazy allocation.

**Nevýhody:**
- Vícenásobný přístup do paměti při TLB miss.
- Vnitřní fragmentace.
- TLB thrashing při velkém working setu.
- I/O režie u swapu, riziko thrashingu.

Mírní se větším TLB (PCID/ASID), huge-pages, lepšími algoritmy výběru oběti, dostatkem RAM.

---

## 5. Souborové systémy

Souborový systém (FS) je vrstva, která dává nestrukturovanému disku strukturu — soubory, adresáře, metadata. Definuje, jak se data fyzicky a logicky rozkládají na médiu.

### Možnosti uložení obsahu souboru

**Souvislý úsek bloků** — jako alokace paměti. Rychlý sekvenční i náhodný přístup, ale fragmentace a problém s růstem souboru. Dnes prakticky nepoužívané pro běžné FS.

**Spojový seznam** — každý blok obsahuje pointer na další. Jednoduché, růst zdarma, ale **náhodný přístup je O(n)** — musíš projít celý řetěz. Jediný špatný blok znepřístupní zbytek souboru. FAT je varianta.

**Indexové struktury (inody)** — samostatný blok obsahuje pole pointerů na datové bloky. **Náhodný přístup O(1)**, sekvenční taky dobrý. U velkých souborů se přidává víceúrovňová indirekce (single/double/triple indirect blocks). Tohle používá ext2/3/4, NTFS.

**Extenty** — místo seznamu jednotlivých bloků se ukládají dvojice `(začátek, délka)`. Pro velké souborové bloky to je radikální úspora režie. Používá ext4, NTFS, btrfs.

| Typ | Sekvenční čtení | Náhodné čtení | Komentář |
|---|---|---|---|
| Souvislý | výborný | výborný | fragmentace, problém s růstem |
| Spojový seznam | dobrý | špatný | FAT |
| Inode | dobrý | dobrý | ext2/3 |
| Extenty | výborný | výborný | ext4, NTFS, btrfs |

### Konkrétní souborové systémy

**FAT / FAT32** — historický, jednoduchý, široce kompatibilní (USB klíčenky). Disk je rozdělen na **clustery** (4–32 KiB). FAT tabulka je v podstatě pole — index = číslo clusteru, hodnota = číslo dalšího clusteru v souboru, nebo `-1` pro konec. **Bez žurnálování**, citlivý na výpadek napájení. Maximální velikost souboru u FAT32 = 4 GiB.

Disková struktura FAT: MBR (boot record + info o FS) → FAT1 → FAT2 (záloha) → root directory → data.

**exFAT** — nástupce FAT32 pro velké disky a soubory (limit 16 EiB). Pořád bez žurnálu.

**NTFS** — moderní FS Windows. Inode-like (MFT — Master File Table), žurnál, ACL, šifrování (EFS), komprese, hard linky.

**ext2 / ext3 / ext4** — Linux. Inode-based. ext3 přidává žurnál, ext4 přidává extenty, větší limity, rychlejší fsck.

**Btrfs, ZFS** — moderní FS s copy-on-write (i pro data, ne jen pro fork), snapshoty, kontrolní součty, integrovaný RAID. ZFS místo žurnálu má transakční model.

### Inode-based FS (ext2/3/4) v detailu

**Inode** je struktura popisující jeden soubor. Obsahuje:
- velikost souboru, vlastník (UID), skupina (GID), přístupová práva,
- časové značky (vytvoření, modifikace, přístup),
- 12 přímých odkazů na datové bloky,
- 1 jednoduchý nepřímý odkaz (blok pointerů na bloky),
- 1 dvojitý nepřímý odkaz (blok pointerů na bloky pointerů),
- 1 trojitý nepřímý odkaz.

Adresář je obyčejný soubor obsahující záznamy `(jméno, číslo inode)`. Jméno **není v inode** — soubor může mít víc jmen v různých adresářích (hardlink), všechny ukazují na týž inode.

**Layout disku** je rozdělen do **skupin bloků** (block groups). Každá skupina obsahuje:
- bitmapu inodu (které jsou volné),
- bitmapu datových bloků,
- tabulku inodu,
- datové bloky.

Důvod rozdělení: na rotujícím disku je výhodné mít inode a jeho data fyzicky blízko. Skupina = lokalita.

**Superblok** obsahuje globální informace (velikost FS, počet inode, ukazatel na první skupinu); má redundantní kopie kvůli odolnosti.

### Žurnálování

**Problém:** zápis na disk není atomický. Když systém spadne v polovině operace (např. „přesun souboru" = aktualizace dvou adresářů), FS zůstane v nekonzistentním stavu — ztracené bloky, dvakrát alokované bloky, atd.

**Řešení:** před změnou hlavního FS zapiš plánovanou operaci do **žurnálu** jako jednu transakci. Po pádu při bootu projde OS žurnál a:
- nedokončené transakce zahodí,
- kompletní transakce, které ještě nebyly zapsány do FS, dokončí (roll-forward),
- kompletní a aplikované transakce jen smaže ze žurnálu.

#### Postup transakce

```
TxB → I_v2 → B_v2 → D_v2 → bariéra → TxE  → checkpoint
```

1. **TxB** — značka začátku transakce.
2. Zápis nové verze inodu, bitmapy, datového bloku do žurnálu.
3. **Bariéra** — disk musí dokončit všechny předchozí zápisy předtím, než zapíše TxE. Bez bariéry by mohl disk přeházet pořadí zápisů a zapsat TxE před daty.
4. **TxE** — značka konce transakce. Tímto je transakce **commit**ovaná.
5. **Checkpoint** — teprve teď se data ze žurnálu zapíšou na své skutečné místo ve FS.
6. Po úspěšném checkpointu se transakce odstraní ze žurnálu.

#### Možné scénáře pádu

| Co je v žurnálu | Co je ve FS | Akce při restartu |
|---|---|---|
| jen část (chybí TxE) | nezměněno | ignorovat — transakce nebyla commitnutá |
| celá (TxB...TxE) | nezměněno | aplikovat (roll-forward) |
| celá + zapsáno do FS, ale neprovedl se cleanup | změněno | znovu aplikovat (operace musí být **idempotentní**) |
| TxB + TxE bez bariéry, chybí data | částečně | KATASTROFA — proto je bariéra povinná |

#### Úrovně žurnálování (ext3/4)

| Úroveň | Co se žurnáluje | Bezpečnost | Výkon |
|---|---|---|---|
| **journal** | metadata + data | nejvyšší | nejnižší (vše se píše 2×) |
| **ordered** (default) | metadata, data se zapíšou před commitem | dobrá | dobrý |
| **writeback** | jen metadata | nejnižší | nejvyšší |

#### Nevýhody žurnálování

- **Dvojnásobné zápisy** (data jdou nejprve do žurnálu, pak na cíl).
- Složitější implementace.
- Zpomalení zápisových operací.
- Pro flash paměti problematické (write amplification).

### Flash paměti — proč jsou jiné

- **Zápis nelze přepsat** — buňka se musí nejdřív smazat (na úrovni celého **bloku**, typicky stovky KiB až MiB).
- **Omezený počet přepisů** — typicky 100 000 až 1 000 000 cyklů na buňku (TLC/QLC mají méně).
- Často měněná data (FAT tabulka, žurnál) by zničila konkrétní místo.

**Write amplification** — změna 1 bajtu = přečtení bloku + smazání + zápis celého bloku.

**Řešení — Flash Translation Layer (FTL):** vrstva v řadiči SSD, která:
- mapuje logické bloky na fyzické (přemapování bez smazání starého fyzického bloku),
- provádí **wear-leveling** (rovnoměrné opotřebení),
- spravuje garbage collection.

Z pohledu OS to vypadá jako normální blokové zařízení. Speciální FS pro raw flash: **JFFS2, UBIFS, NILFS** (log-structured).

---

## 6. Bezpečnost

### Trusted Computing Base (TCB)

**TCB** je množina **všech komponent, kterým systém musí věřit**, aby udržel bezpečnostní záruky. Pokud kterákoli část TCB selže (chyba, kompromitace), bezpečnost celého systému padá.

Příklady toho, co je v TCB:
- hardware (CPU, RAM, paměťové sběrnice, firmware UEFI/BIOS),
- jádro OS,
- privilegované procesy (init, autentizace, root),
- hypervizor (u virtualizovaných systémů),
- kryptografické klíče a HW jako TPM,
- správci systému jako lidé.

**Princip:** TCB by měla být **co nejmenší** — méně kódu = méně chyb. Mikrojádro snižuje TCB tím, že vyhání ovladače mimo ring 0. Sandboxy (např. seccomp) snižují TCB pro konkrétní aplikace.

### Řízení přístupu — model

Teoretický model: **matice řízení přístupu**. Řádky = **subjekty** (uživatelé, procesy), sloupce = **objekty** (soubory, sokety, zařízení). Buňka říká, jaká práva má daný subjekt k danému objektu.

|        | Obj1 | Obj2 | Obj3 | Subj2 |
|--------|:----:|:----:|:----:|:-----:|
| alice  | R    | RW   |      | send  |
| bob    |      | RX   |      | control |
| root   | RW   |      | RWX  | recv  |

Subjekty **mohou být i objekty** (např. process může být cílem `kill` od jiného procesu).

V praxi je matice řídká, dynamická, obrovská — ukládat ji jako matici nemá smysl. Dvě praktické varianty:

#### Access Control List (ACL) — uložení po sloupcích

Každý objekt si nese **seznam, kdo k němu má jaký přístup**. Tradiční model UNIXu:

```
$ ls -l /etc/passwd
-rw-r--r-- 1 root root 2843 Nov 22 /etc/passwd
```

Tři skupiny: vlastník, skupina, ostatní. Každá tři práva: read, write, execute. Moderní systémy (POSIX ACL, NTFS ACL) podporují **rozšířené ACL** — pravidla pro libovolné uživatele/skupiny, negativní oprávnění (zakázat), metaoprávnění (kdo smí měnit ACL).

**Výhoda:** snadné odpovědět „kdo má přístup k tomuto souboru".

**Nevýhoda — ambient authority:** proces běží s plnými právy svého uživatele. Když si stáhneš `evil.sh` a pustíš ho, má přístup ke všem tvým souborům. Je těžké říct „spusť tenhle program, ale jen s přístupem k tomuhle adresáři".

#### Capability list — uložení po řádcích

Každý subjekt si nese seznam **schopností (capabilities)**, kde každá schopnost je token tvaru `(objekt, oprávnění)`. Bez schopnosti objekt **vůbec neexistuje** — nelze ho najít, oslovit, otevřít.

Schopnosti se předávají explicitně (např. přes IPC, fork, init). Princip *least privilege* je vestavěný: dítě dostane jen ty schopnosti, které mu rodič předal.

**Výhody:**
- Žádná ambient authority.
- Nikdo nemůže předat právo, které sám nemá.
- Krásně se škáluje (modulární programy, sandboxy).

**Nevýhody:**
- Hůře se odpovídá „kdo má přístup k objektu" (musíš projít všechny subjekty).
- Méně intuitivní pro běžné uživatele.

Capability-based systémy: některé mikrojádra (L4, seL4), webové prohlížeče (capability URLs), Capsicum (FreeBSD), částečně Linux capabilities.

| | ACL | Capabilities |
|---|---|---|
| Otázka „kdo to může číst?" | snadná | obtížná |
| Otázka „co může tento proces?" | obtížná | snadná |
| Ambient authority | ano (problém) | ne |
| Předávání práv potomkům | celá identita | jen předané schopnosti |
| Modulárnost | nižší | vyšší |

### Útok přetečením zásobníku (stack buffer overflow)

#### Princip útoku

Zásobník typicky vypadá takhle (rostoucí směrem dolů):

```
       vyšší adresy
   ┌────────────────┐
   │ argumenty volání│
   ├────────────────┤
   │ návratová adresa│ ← KLÍČOVÉ
   ├────────────────┤
   │ uložený rbp    │
   ├────────────────┤
   │ lokální buf[64]│ ← do tohoto pole píšeš
   └────────────────┘
       nižší adresy
```

```c
void f() {
    char buf[64];
    gets(buf);  // ŽÁDNÁ kontrola hranic!
}
```

Když uživatel zadá víc než 64 bajtů, `gets` přepíše uložený rbp, pak **návratovou adresu**, pak argumenty. Útočník kontroluje, kam se vrátíme po `f()`.

**Cíle útoku:**
1. **Shellcode injection** — útočník vloží do bufferu strojový kód (typicky spuštění shellu) a návratovou adresu nasměruje na začátek bufferu. Po návratu z funkce procesor vykoná shellcode.
2. **Return-Oriented Programming (ROP)** — když je zásobník nespustitelný (NX bit), útočník neposílá kód, ale skládá útok z malých kousků existujícího kódu (**gadgetů**) zakončených instrukcí `ret`. Zásobník naplní řetězcem návratových adres na tyto gadgety. Turing-complete bez vlastního kódu.

**Omezení shellcode:** typicky se předává jako řetězec, takže nesmí obsahovat `\0` (jinak se ukončí). Útočníci používají alfanumerické kódování, dekodéry, ROP.

#### Obrana

**Nespustitelný zásobník** (NX bit / XD bit / ARM UXN) — stránky zásobníku jsou označené `no execute`. Pokus o spuštění kódu z nich vyvolá page fault. Tím padá injection shellcode (ale ne ROP).

**ASLR (Address Space Layout Randomization)** — při každém spuštění se náhodně rozmístí stack, heap, knihovny, případně i binárka (PIE). Útočník nezná, kam přesně skočit. Účinné proti přesnému zacílení, ale dá se obejít leakem adresy.

**Stack canary (stack protector)** — kompilátor vloží před uloženou návratovou adresu náhodnou hodnotu (canary). Před `ret` se kontroluje, zda je nezměněná. Pokud útočník přepsal návratovou adresu, přepsal i canary → program detekuje a abortuje.

**Retguard** (OpenBSD) — návratová adresa se při vstupu do funkce XORuje s tajnou hodnotou a před návratem zase. Útočníkův přepis se po dekódování stane nesmyslnou adresou.

**Bezpečné funkce** — `strncpy` místo `strcpy`, `snprintf` místo `sprintf`, `fgets` místo `gets`. Validace délky vstupu před zápisem.

**Bezpečné jazyky** — Rust, Go, Java, Python kontrolují hranice polí runtime nebo staticky. Většina přetečení v moderních CVE je v C/C++ kódu.

**Princip nejmenšího oprávnění (least privilege)** — i když útok uspěje, omezí jeho dopad. Sandboxing, capability dropping, oddělené UID pro síťové služby.

V praxi se obrany kombinují: typický binární soubor v Linuxu má NX, ASLR (PIE), stack canaries i FORTIFY_SOURCE.

---

## 7. Virtualizace

Virtualizace = abstrakce hardwaru tak, že **více operačních systémů** může běžet na jednom fyzickém stroji s vzájemnou izolací. Každý OS je v iluzi, že má svůj vlastní hardware.

### Pojmy

- **Hostitel (host)** — fyzický stroj, na kterém vše běží.
- **Hypervizor (VMM)** — software, který emuluje virtuální HW a řídí běh VM. *Type 1* (bare-metal, Xen, ESXi) běží přímo na HW, *Type 2* (VirtualBox, VMware Workstation) běží jako aplikace nad hostitelským OS.
- **Host (guest)** — OS běžící uvnitř VM.

### Typy virtualizace

- **Plná virtualizace** — host neví, že je virtualizován. Implementace přes trap-and-emulate. Klasicky VMware, KVM, ESXi.
- **Paravirtualizace** — host je modifikovaný, ví o virtualizaci a explicitně volá hypervizor (hypercalls) místo problematických instrukcí. Rychlejší, ale potřebuje upravený OS. Xen v původní formě.
- **Emulace** — kompletní softwarová interpretace HW včetně instrukční sady. Pomalé, ale lze emulovat jinou architekturu (ARM na x86 atd.). QEMU bez akcelerace.
- **Kontejnery (jiný level)** — sdílí jádro, jen izolují namespace. Dockery, LXC. Striktně vzato to není virtualizace v této definici.

### Problém: privilegované instrukce

Moderní CPU má dva relevantní režimy: ring 0 (jádro) a ring 3 (uživatel). Nemůžeš nechat hostovo jádro běžet v ring 0 — kdyby provedlo `lgdt` (změna globální descriptor tabulky) nebo `cli` (zakázání přerušení), ovlivnilo by to celý fyzický systém, nejen vlastní VM.

Řešení (před hardwarovou asistencí): **host běží v ring 3** a hypervizor sedí v ring 0 (případně používá ringy 1/2 — historie). Jádro hosta si ale myslí, že je v ring 0.

### Trap-and-emulate

Klasická metoda plné virtualizace:

1. Nepriviligované instrukce se vykonávají **nativně** v ring 3 — žádný overhead.
2. Pokus o privilegovanou instrukci v ring 3 vyvolá výjimku (**trap**), kterou zachytí hypervizor.
3. Hypervizor zjistí, **co host chtěl**, provede to (nebo emuluje výsledek pro tu jednu VM, ne pro celý fyzický systém) a vrátí řízení zpátky do hosta.
4. Host pokračuje, jako kdyby instrukce proběhla normálně. Iluze zachována.

**Požadavek na CPU (Popek-Goldberg, 1974):** všechny **citlivé instrukce** (ty, co mění globální stav nebo na něm závisí) musí být **privilegované** — tedy v ring 3 vyhazovat trap. Pokud nejsou (a původní x86 takových několik mělo, např. `popf`), nelze čistě trap-and-emulate. Řešení byly složitější techniky (binární překlad — VMware ESX 1.0).

### Virtualizace systémových volání

Když aplikace v hostovi volá `read()`, instrukce SYSCALL pošle CPU do ring 0 — jenže ring 0 není host, ale hypervizor. Co teď?

Hypervizor zachytí trap, podívá se, že to byl SYSCALL z hosta, a **přesměruje** ho do hostova jádra (které sedí v ring 3, ale hypervizor mu zinscenuje, že je „v ring 0"). Po dokončení syscallu se dostane návrat zpět hypervizoru, který předá řízení zpět do uživatelské části hosta.

Větší overhead než nativní syscall (každý přechod jde přes hypervizor), ale funguje.

### Virtualizace stránkovacích tabulek

Tady je to nejhezčí. Host má vlastní stránkovací tabulky a věří, že mapuje **virtuální adresu → fyzickou adresu**. Jenže ta „fyzická" adresa pro něj není fyzická pro hostitele — hypervizor mu přiděluje jen kus skutečné RAM.

Máme **tři vrstvy adres:**
- GVA = Guest Virtual Address (co vidí aplikace v hostu),
- GPA = Guest Physical Address (co host považuje za fyzickou),
- HPA = Host Physical Address (co je skutečně v RAM).

#### Shadow page tables (softwarové řešení)

Hypervizor udržuje **vlastní** stránkovací tabulky, které mapují přímo GVA → HPA. Když host modifikuje své „fyzické" tabulky (GVA → GPA), hypervizor to zachytí (host nemá oprávnění zápisu) a synchronizuje shadow tabulky.

CPU používá shadow tabulky, host o nich neví. Funkční, ale drahé na údržbu — každá změna v hostových tabulkách = trap + synchronizace.

#### Nested page tables — EPT/NPT (HW asistence)

Modernější řešení. CPU překládá adresy ve **dvou krocích**:
1. host page table: GVA → GPA,
2. hypervizor page table (EPT u Intelu, NPT u AMD): GPA → HPA.

Obojí dělá hardware. Host volně mění své tabulky, hypervizor zasahuje jen občas. Větší TLB tlak, ale výrazně lepší než shadow tables.

### Hardwarově asistovaná virtualizace

Intel VT-x (2005), AMD-V přidaly nový režim CPU:

- **Root mode** — kde běží hypervizor. Plný přístup.
- **Non-root mode** — kde běží VM. Má vlastní ring 0 i ring 3, takže host může být v ring 0 (ze svého pohledu) bez ohrožení hostitele.

Privilegované instrukce hosta v non-root mode buď běží přímo (pokud nejsou citlivé pro celý systém), nebo způsobí **VM exit** — řízení skočí do hypervizoru s informací o příčině. Tohle je čisté „trap-and-emulate", ale na hardwarové úrovni a tedy rychlé.

K tomu **EPT/NPT** pro paměť, **VPID** (analogie ASID pro VM, kvůli TLB) a další optimalizace. Moderní hypervizor (KVM, Xen HVM) prakticky nemá výkonnostní propad oproti nativnímu běhu, dokud se nepřepíná často mezi VM a host (což může být problém pro síťové I/O, řeší SR-IOV, virtio atd.).

**Nested virtualization** — VM uvnitř VM. Vyžaduje, aby host viděl VT-x ve svém CPU. Funguje, ale s overheadem.

### Souhrn virtualizačních technik

| Oblast | Princip |
|---|---|
| Trap and emulate | privilegovaná instrukce hosta → trap → hypervizor emuluje |
| Virtualizace syscalls | trap přesměruje syscall do hostova jádra |
| Virtualizace stránkování | shadow tables (SW) nebo EPT/NPT (HW) |
| HW asistence | non-root mode, VM exit, VT-x/AMD-V |

---

## Závěrečné shrnutí — jak to do sebe zapadá

- **Systémová volání** jsou kontrolovaný most z uživatelského do jádrového kódu. Kdyby neexistovaly, neměli bychom čisté oddělení uživatelské aplikace a jádra.
- **Procesy** zajišťují izolaci, **vlákna** zajišťují paralelismus uvnitř jednoho adresního prostoru. PCB drží proces, TCB drží vlákno.
- **Synchronizace** zajišťuje korektnost při sdílení dat. Mutex, semafor, condition variable, spin-lock — každý má své místo. Deadlock = porušení Coffmanových podmínek.
- **Virtuální paměť** umožňuje izolaci procesů, sdílení (kód, COW), víc paměti než RAM (swap), ochranu jádra. Stránkování + TLB jsou srdce moderních systémů.
- **Souborové systémy** strukturují disk. FAT je historický, inode je standard, extenty jsou moderní. Žurnál chrání před nekonzistencí po pádu.
- **Bezpečnost** stojí na malé TCB, modelu řízení přístupu (ACL/capabilities) a obraně proti nízkoúrovňovým útokům (overflow → NX, ASLR, canary).
- **Virtualizace** rozšiřuje princip izolace o celé OS. Trap-and-emulate je teoretický základ, hardwarová asistence (VT-x + EPT) ho dělá rychlým v praxi.

Klíčový vzor, který se opakuje napříč: **OS používá hardwarové prostředky (privilegované režimy, MMU, atomické instrukce, traps) k vynucování abstrakcí, na kterých stojí všechno ostatní.** Bez ring 0/3 by neexistovala ochrana jádra. Bez MMU by neexistovala virtuální paměť. Bez atomických instrukcí by neexistovaly zámky. Bez VT-x by hypervizor nebyl efektivní. Hardwarové mechanismy jsou základ, OS je staví do struktury, kterou nakonec aplikace používají.

---

## Tipy ke zkoušce

- Buď připravený nakreslit překlad adresy přes víceúrovňové stránkování (rozdělení virtuální adresy na 4 kusy + offset).
- Umět rozhodnout: data race / deadlock / livelock / starvation — která situace to je.
- Coffmanovy podmínky umět vyjmenovat **a** říct, jak se která dá porušit.
- Tabulka „co sdílí vlákna jednoho procesu" je oblíbená otázka.
- U syscallu vědět, co je v `rax` před a po (číslo syscallu × návratová hodnota).
- U FS umět říct, proč FAT není vhodný pro velké soubory (sekvenční průchod tabulky).
- U bezpečnosti: ASLR + NX + canary není nezávislé — všechny tři útok ztěžují, ale dohromady ho prakticky znemožňují bez další informace (např. info leak).
- U virtualizace: vědět rozdíl shadow page tables vs. EPT/NPT (kdo udržuje, kolik traps).
