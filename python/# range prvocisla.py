# range prvocisla
print("zadej prvni cislo")
prvni_cislo = int(input())
print("zadej druhe cislo")
druhe_cislo = int(input())
odecet = druhe_cislo - prvni_cislo
x = prvni_cislo
#
#for i in range(prvni_cislo, druhe_cislo + 1):
while odecet > 1:
    opakovani = x - 1
    while opakovani > 1:
        normalni_deleni = x // opakovani
        celociselny_deleni = x / opakovani
        if normalni_deleni - celociselny_deleni != 0:
            print (opakovani)
            break
        else:
            opakovani = opakovani - 1
    x = x + 1
    odecet = odecet - 1
