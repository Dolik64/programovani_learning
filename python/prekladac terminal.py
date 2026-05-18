# prekladac aka Jirka      (os.path.expanduser

from pathlib import Path


radek = []

vysledek = []

overeni = 0

zadani_jazyka = 0

print()

# print("chces tvoje slovo cesky?")
f = open("prekladac.txt")
for line in f:
    radek.append(line.strip().split())
    print(radek[0][0])
    radek.clear()


print()
print("napis slovo ze seznamu")
slovo_cesky = str(input())

while overeni == 0:
    f = open("prekladac.txt")
    for line in f:
        radek.append(line.strip().split())
        if radek[0][0] == slovo_cesky:
            vysledek.append(radek[0][1])
            vysledek.append(radek[0][2])
            overeni = 1
            #  print("jarmil")
            break
        radek.clear()
    if overeni == 0:
        print("tvoje slovo neni v seznamu, zkus to znovu")
        slovo_cesky = str(input())
print()
print("pokud chces slovo anglicky napis 1, pokud francouzky napis 2")
jedna_dva = str(input())

while zadani_jazyka == 0:
    if jedna_dva == str("1") or jedna_dva == str("2"):
        zadani_jazyka = 1
        #print("konec")
    else:
        #jedna_dva = str(input())
        print("napis prosim 1 nebo 2")
        print()
        jedna_dva = str(input())


if jedna_dva == str(1):
    print()
    print(vysledek[0])
    print()
elif jedna_dva == str(2):
    print()
    print(vysledek[1])
    print()
