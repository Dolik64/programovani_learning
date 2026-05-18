#bedny
import random
tvoje_cislo = str("tvoje cislo je ")
for i in range(1):
    print()
    print("kolik vsazis? zadej castku")
    print("mozna vyhra az 50 000Kč")
    castka = int(input())
    print("jake cislo vsazis?")
    x = int(input())
    random_cislo = random.randint(1, 8)
    if random_cislo == 4:
        print("vyhral jsi")
    else:
        print("prohral jsi")
        padlo = x + random_cislo
        print(tvoje_cislo + str(padlo))
    
   # print()
   # print()
    #print("nevyhrsl jsi, protoze padlo toto cislo")
    #debil = x + random_cislo
    #print(debil)