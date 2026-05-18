#myslim si cislo
konec = 0
pocet_pokusu = 1    #pocet pokusu je 1
import random
cislo = random.randint(100,120)
print("myslim si cislo, zkus uhodnout jake")
while konec == 0:
    tipovacka = int(input())
    print()
    if tipovacka == cislo:
        print()
        print("presne tak, gratuluju")
        print()
        print("zvladl jsi to na " + str(pocet_pokusu) + " pokusu")
        print()
        konec = 1
    else:
        if tipovacka > cislo:
            print()
            print("moje cislo je mensi")
            pocet_pokusu = pocet_pokusu + 1
        else:
            print()
            print("moje cislo je vetsi")
            pocet_pokusu = pocet_pokusu + 1
