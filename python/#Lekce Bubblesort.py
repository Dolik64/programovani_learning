#Lekce Bubblesort
# 1 2 12 8 7
# 1 2 12 8 7
# 1 12 2 7 8
print("budeme radit seznam vzestupne")
print()
print("napis seznam cisel s mezerama")
vstup = input().split() 
#int(vstup)ß
  #.strip()
#print(seznam)
pocet_pozic = len(vstup)
krok = 0
mezipamet1 = 0   #"0"
mezipamet2 = 0   #"0" 
#porovnat = vstup
#pocet_pozic = len(vstup)
for i in range(pocet_pozic ):   # - 1
    krok = 0
    for i in range(pocet_pozic - 1):   # - 1
        mezipamet1 = (vstup[krok])
        mezipamet2 = (vstup[krok + 1])
        int(mezipamet1) + 0
        int(mezipamet2) + 0
        #print(mezipamet1)
       # print(mezipamet2)
        #print(pocet_pozic)
        if int(mezipamet1) > int(mezipamet2):
            #vstup[krok] < vstup[krok + 1]
            int(mezipamet1)   #int a str prevod delam kvuli testu
            int(mezipamet2)
            print()
            print("prehazuji " + mezipamet1 + " a " + mezipamet2)
            print()
            (vstup[krok]) = (mezipamet2)
            (vstup[krok + 1]) = (mezipamet1)
            krok = krok + 1
        else:
            krok = krok + 1
        
       # vstup[krok] = vstup[krok + 1]
       # vstup[krok + 1] = vstup[krok]
       #neumim psat
        
print(" ".join(vstup))
