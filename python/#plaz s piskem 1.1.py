#plaz s piskem

import math


#vstup    
#1 sirka plaze
#2 souradnice startu
# 3 souradnice cile
#4 mam nemam prkno
#5 pocet pisku
#6... souradnice pisku


#vystup
#1 delka nejkradsi cesty
#2 kroky jsou delkou trasy plus 00

from xmlrpc.client import MAXINT


sirka = input()
start = input()
cil = input()
nemam_prkno = input()
pocet_pisku = input()

cil_x = int(cil[0])
cil_y = int(cil[1])
#souradnice cile potrebujeme na vypocet vzdalenosti od mozne pozice, proto si je definujeme hned na zacatku
pisky = []
#seznam souradnic pisku
krok = 0
#krok je pocitadlo kroku, ktery jsme usli
seznam_pozic = []
# do tohoto seznamu pridavame pozice, kudy jsme sli
sousedi = []
#toto je seznam policek, kam muzeme vstoupit z aktualni pozice
winner = MAXINT
#winner je vzdalenost od cile, budeme hledat vzdy tu nejmensi moznou, takze zacneme s nekonecnem
for i in range (int(pocet_pisku)):
    souradnice_pisku = input()
    pisky.append(souradnice_pisku)
#kazdy input souradnic pisku se pridava do seznamu pisky

#print(pisky)
#print("------------")


if start == cil:
    
    print(0)
    print(start)

elif cil in pisky:
    print("nema reseni")
    
else:
    #hranice kontroluje, jestli nejsme mimo zadané bludiště
    hranice = int(sirka) - 1



    aktualni_pozice = start
    krok = 0
    seznam_pozic.append(str(aktualni_pozice))
    while str(aktualni_pozice) != str(cil):
    
        #nejdriv si zjistim souradnice aktualni pozice
        x = str(aktualni_pozice[0])
        y = str(aktualni_pozice[1])
        #pote jednu souradnici zmenim tak abych dostal sousedici policko,   policko "nahore" ma y souradnici o 1 vetsi nez aktualni pozice atd
        x = int(x)
        y = int(y) + 1
        if y > hranice:
            y = y * -1
            #pokud se nachazime mimo zadane bludiste, tedy presahujeme hranici, potom algoritmus prida do cisla "-" aby ho vyradil z nasledujicich kroku
        nahore = str(x)+str(y)
        x = str(aktualni_pozice[0])
        y = str(aktualni_pozice[1])
        if nahore.find("-") == -1:
            sousedi.append(nahore)
            #do seznamu sousedi se pridaji jen takove pozice, ktere se nachazi v zadanem bludisti



        x = int(x)
        y = int(y) - 1
        dole = str(x)+str(y)
        x = str(aktualni_pozice[0])
        y = str(aktualni_pozice[1])
        if dole.find("-") == -1:
            sousedi.append(dole)

        x = int(x) - 1
        y = int(y)
        levo = str(x)+str(y)
        x = str(aktualni_pozice[0])
        y = str(aktualni_pozice[1])
        if levo.find("-") == -1:
            sousedi.append(levo)


        x = int(x) + 1
        y = int(y)
        if x > hranice:
            x = x * -1
        pravo = str(x)+str(y)
        x = str(aktualni_pozice[0])
        y = str(aktualni_pozice[1])
        if pravo.find("-") == -1:
            sousedi.append(pravo)


        sousedni_pisky = list(set(sousedi).intersection(pisky))
        #nyni vytvorime seznam sousednich pozic, na kterych se nachazi pisek
        sousedi = list(set(sousedi) - set(pisky))
        #ze seznamu sousedi se odeberou pozice s prekazkami
        



        if len(sousedi) == 0:
            print("nema reseni")
            break
        #pokud nema algoritmus dal kam jit, vyhodnoti ze situace nema reseni

        #i = 0
        for i in range(len(sousedi)):
            
            x = int(sousedi[i][0])
            y = int(sousedi[i][1])
            vzdalenost = math.sqrt(((x-cil_x)**2)+((y-cil_y)**2))
            #nyni pomoci vzorce pro vypocet delky vektoru zjistime vzdalenost souseda od cile
            if vzdalenost < winner:
                winner = vzdalenost
                aktualni_pozice = sousedi[i]
                
            #prochazime seznam moznych sousedu a vybirame toho souseda, ktery je k cili nejbliz, pokud jsou dva stejne blizko, algoritmus vybere toho prvniho


        #do seznamu pridame krok, ktery jsme udelali a cely cyklus se opakuje
        seznam_pozic.append(aktualni_pozice)
        krok = krok + 1
        winner = MAXINT
        sousedi.clear()



    
    print(krok)
    for i in range(len(seznam_pozic)):
        print(seznam_pozic[i])
            
        
    #print(start)
    #pass





