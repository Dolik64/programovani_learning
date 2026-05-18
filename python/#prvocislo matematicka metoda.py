#prvocislo matematicka metoda
print("napis cislo")
x = int(input())

opakovani = x - 1
pravda = 0
vypnout_program = 0
if x != 0:
    if x != 1:
    
    
    
    
        while opakovani >= 2:
            float_cislo = x / opakovani
            int_cislo = x // opakovani
            if float_cislo - int_cislo == 0:
                print()
                print("neni to prvocislo")
                pravda = 1
                print()
                print("je to delitelne cislem: " + str(opakovani))
                print()
                break
        
            else:
                opakovani = opakovani - 1
    #if vypnout_program == 1:
   #     pravda = 3
        if pravda == 0:
            print()
            print("je to prvocislo")
            print()
    else:
        print()
        print("1 se blbe urcuje, zadej jiny cislo")
        print()
else:
    print()
    print("0 se blbe urcuje, zadej jiny cislo")
    print()
    #vypnout_program = 1
#slozitost programu se odviji od velikosti cisla x, pokud mluvime o slozitosti jednoho cyklu, je to 3n
