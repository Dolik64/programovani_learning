#prvocislo
#2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41
print("napis cislo")
x = int(input())
pocet_cifer_x = int(len(x))
pocet_cifer_vysledek = 0
deleni_dvema = 0
cele_cislo = ""
if x == 2:
    print("je to prvocislo")
elif x == 3:
    print("je to prvocislo")
elif x == 5:
    print("je to prvocislo")
elif x == 7:
    print("je to prvocislo")
else:
    if int(x) > 7:
        deleni_dvema = int(x) / 2 
        #cele_cislo = str(type(deleni_dvema))
        #print(str(cele_cislo))
        #if str(cele_cislo) == str("float"):
        #pocet_cifer_vysledek = int(len(deleni_dvema))
        #if pocet_cifer_vysledek > pocet_cifer_x:
        print("neni to prvocislo")

    else:
        print("neni to prvocislo")
    

