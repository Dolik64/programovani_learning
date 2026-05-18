#pocitadlo dell
print("napis cislo")
prvni_cislo = int (input())
print("napis druhe cislo")
druhe_cislo = int  (input())
x = int (prvni_cislo)- 1
jedna = 1
for i in range(prvni_cislo - 1, druhe_cislo + 1):
    pocet_cisel = len(str(x))
    for l in range(1,pocet_cisel):
        pozice = str(x)[pocet_cisel - int (jedna)]
        if int (pozice) == 4:
            print(x)
        else:
            jedna = jedna + 1
    x = x + 1


    #print(pozice)
    
    #x = int(55)
    #pozice = str(x)[0]
    #print(pozice)
    #int (pozice)
    #if int (pozice) == 5:
       # print(x)
    #print(pocet_cifer)
    #print("jirka")
    #pocet_cifer = len(str ((x))
    #if x[pocet_cifer] == 4:
        #print(x)

