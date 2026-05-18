#range prvocisla doma
ano = 0
print("napis cislo")
print()
print()

num = int(input())
print()
print()
konstanta = 0
x = 100
while x > 0:
    x = num - konstanta
    hodnota = x - 1
    while hodnota > 1:
        celociselny_podil = x // hodnota
        debilni_podil = x / hodnota
        if celociselny_podil - debilni_podil == 0:
           # print("neni prvocislo")
            ano = 1
            #print(x)
            break
            #hodnota = hodnota - 1
        else:
            hodnota = hodnota - 1
    if ano == 0:
        #print("je to prvocislo")
        print(x)
    ano = 0
    konstanta = konstanta + 1
