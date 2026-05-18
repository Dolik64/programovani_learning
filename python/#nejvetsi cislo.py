#nejvetsi cislo
print("napis cislo")
x = int(input())
nejvetsi_cislo = x
nebyla_zadana_data = "nebyla zadána vstupní data"
while 4 < 10:
   # print("napis cislo")
   # x = int(input())
    if x == -1:
        if nejvetsi_cislo == -1:
            print()
            print(nebyla_zadana_data)
            print()
            exit()
        else:
            print()
            print("nejvetsi cislo je: " + str(nejvetsi_cislo))
            print()
            exit()
    elif  x > nejvetsi_cislo:
            nejvetsi_cislo = x
            print("napis cislo")
            x = int(input())

    else:
        #nejvetsi_cislo = 0
       # int(nejvetsi_cislo)
        #nejvetsi_cislo = x
        print("napis cislo")
        x = int(input())
        