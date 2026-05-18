#funce a operace s retezcem
"""č. 2: Prohlédněte si prezentaci Python_6_znakove_retezce_metody.

Úkol č. 3: Napište program, který si načte posloupnost čísel zadaných na jednom řádku oddělených mezerami. A dále:

1. Vypište čísla v opačném pořadí, opět na jeden řádek, čísla budou oddělena mezerami.

2. Zjistěte, kolik z nich se rovná poslednímu.

3. Vypište číslo, které je nejmenší. Dále uveďte, na kolikátém místě pole se nachází nejmenší číslo. 
Vyskytuje-li se tam vícekrát, vypište všechny pozice výskytů.
"""
print("napis retezec cislis a oddeluj je mezerama")
retezec = str(input())
x = 0
kolik_stejnych = -1
print()
print("nyni vypisu tento retezec pozpatku")
print(retezec[::-1])
print()
print("ale budem pracovat s tim puvodnim")
print(retezec)
print()
pocet_znaku = len(retezec) - 1
hodnota_posledniho_cisla = (retezec[pocet_znaku])
for i in range (pocet_znaku + 1):
    if (retezec[x]) == str(hodnota_posledniho_cisla):
        kolik_stejnych = kolik_stejnych + 1
        x = x + 1 
    else:
        x = x + 1

print("poslednimu cislu se rovna: " + str(kolik_stejnych) + " cisel")
print()

pole = retezec.strip().split()
#print(pole)
print("nejmensi cislo je: " + str(min(pole)))
nejmensi_cislo = int(min(pole))
#print(nejmensi_cislo)
