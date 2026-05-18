#pocitadlo tuning
print("napis cislo pocatecni")
cislo_pocatecni = int (input())
print("napis cislo posledni")
cislo_posledni = int (input())
#obecne_cislo = input()
#pocet_cifer = obecne_cislo%10
#print(pocet_cifer)
#print(int (obecne_cislo) % 10)
x = int (cislo_pocatecni)
while x <= (cislo_posledni):
    print(x)
    if x < 10:
        if x == 4:
            print(x)
    else:
        #zbytek = x
        podil = x
        while podil > 10:
            #print(zbytek)
            zbytek = int (x % 10)
            print(zbytek)
            if zbytek == 4:
                print(x)
            else:
                podil = int (podil // 10)
            
    x = x + 1


         #if int(zbytek == 4):
                  #  print(x)
               # else:
             #       podil = int (x // 10)

    
