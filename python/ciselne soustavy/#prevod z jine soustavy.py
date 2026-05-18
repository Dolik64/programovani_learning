#prevod z jine soustavy 
#**


print("prevadime do desitkove soustavy")
print("zadej cislo v divne soustave")
cislo = int(input())
print("zadej o jakou soustavu jde")
soustava = int(input())

cislo = str(cislo)
delka = len(cislo)
cislo = cislo[::-1]
krok = 0
vysledek = 0
for i in range(delka):
    mezikrok = cislo[krok]
    mezikrok = int(mezikrok)
    vysledek = vysledek + (mezikrok * (soustava ** krok))
    #print(vysledek)
    krok = krok + 1


print("je to tam")
print(vysledek)
#cislo = int(cislo)

