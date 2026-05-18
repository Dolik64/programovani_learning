#zapalky random verze
import random
pocet = random.randint(18,30)
konec = 0
odber = 0
podvod = 0
print("hra pro dva hrace")
print("kazdy ma jeden tah, smi se ubirat 1 2 nebo 3 zapalky ze stolu")
print("nikdo nevi kolik zapalek na stole je a vyhrava ten, kdo ubere tu posledni")
print()
print("jak se jmenuje prvni hrac")
hrac1 = str(input())
print()
print("jak se jmenuje druhy hrac")
hrac2 = str(input())
print()
while konec == 0:

    print("na tahu je " + hrac1)
    #print(pocet)
    print("odeber 1 2 nebo 3 zapalky")
    odber = int(input())

    if 0 >= odber or odber >= 4:       # or
        print("neplatna hodnota, zkus to znova")
        podvod = 1
        while podvod == 1:
            odber = int(input())
            print("neplatna hodnota, zkus to znova")
            if 0 < odber < 4:
                podvod = 0
    print()
    if odber > pocet:
        print("zadal jsi moc vysoke cislo")
        print()
        odber = 0
    pocet = pocet - odber
    if pocet == 0:
        print("vyhrava hrac " + hrac1)
        print("gratulujeme")
        print()
        konec = 1
        break

    print("na tahu je " + hrac2)
    #print(pocet)
    print("odeber 1 2 nebo 3 zapalky")
    odber = int(input())

    if 0 >= odber or odber >= 4:       # or
        print("neplatna hodnota, zkus to znova")
        podvod = 1
        while podvod == 1:
            odber = int(input())
            print("neplatna hodnota, zkus to znova")
            if 0 < odber < 4:
                podvod = 0
    print()
    if odber > pocet:
        print("zadal jsi moc vysoke cislo")
        print()
        odber = 0
    pocet = pocet - odber
    if pocet == 0:
        print("vyhrava hrac " + hrac2)
        print("gratulujeme")
        print()
        konec = 1
        break

