#ciselny soucet
print("napis cislo")
x = input()
opakovani = len(str(x))
pocet_cifer = len(str(x)) - 1
ciferny_soucet = 0
int(x)
cifra = 0
for i in range(opakovani):
    cifra = str(x)[pocet_cifer]
    ciferny_soucet = ciferny_soucet + int(cifra)
    pocet_cifer = pocet_cifer - 1
print(ciferny_soucet)
#3n
