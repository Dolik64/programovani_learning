#soucet
print("zadej cislo")
x = int(input())
ciselny_soucet = 0
while 4 > 2:
    if x == -1:
        print()
        print("soucet je: " + str(ciselny_soucet))
        print()
        exit()
    else:
        ciselny_soucet = ciselny_soucet + x
        print("zadej cislo")
        x = int(input())