#soustavy
#x = 7348 // 10
#y = 7348 % 10
#print(x)
#print(y)
print("napis soustavu")
soustava = int (input())
if 2 <= soustava <= 9:
    print("dem na to")

else:
    print("napsal si to spatne kamo")
    exit()
print("napis cislo v desitkove soustave")
cislo = int(input())
minus_znamenko = str("")
if cislo < 0:
    cislo = abs(cislo)
    minus_znamenko = str("-")

deleni = 0
zbytek = 0
pocet_cifer = len(str(cislo))
vypis = str("")
int(cislo)
deleni = int(cislo)
#for i in range(int(pocet_cifer)):
print("       ")
while int(deleni) > 0:
    #print(deleni)
    zbytek = int(deleni) % int(soustava)
    vypis = vypis + str(zbytek)
    int(zbytek)
    #print(zbytek, end='')
    
    deleni = int(deleni) // int(soustava)
vypis = vypis[: :-1]
print(minus_znamenko + vypis)
print()
print()