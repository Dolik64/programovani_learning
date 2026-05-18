#domaci ukol 2
#pocitadlo 
print("napis cislo")
prvni_cislo = int (input())
print("napis druhe cislo")
druhe_cislo = int  (input())
print("        ")
x = int (prvni_cislo)#- 1
jedna = int(1)
num = druhe_cislo - prvni_cislo
prvni_mensi = prvni_cislo
for i in range(prvni_mensi , druhe_cislo + 1):
    pocet_cisel = 1
    pocet_cisel = len(str(x))
    jedna = int(1)
    for l in range(pocet_cisel ):
        pozice = str(x)[int (pocet_cisel) - int (jedna)]
        if int (pozice) == 4:
            print(x)
            jedna = jedna + 1
            break
            #x = x + 1
            #break
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

