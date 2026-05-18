#obsahuje
print("napis cislo")
x = int(input())
vysledek_deleni = x / 2
retezec = str(vysledek_deleni)
pocet_cifer = len(retezec) - 1
#opakovani = pocet_cifer - 1

if int(retezec[pocet_cifer]) == 0:
    print("je to delitelne 2")
else:
    print("neni to delitelne 2")
#rozhodovani = ("." in retezec)
#print(retezec)
#print(rozhodovani)
#if str(rozhodovani) == str("True"):
##    print("neni delitelne 2")
#else:
 #   print("je delitelne 2")