#na vstupu dostaneme dve cela cisla
#oddelene mezerou
#na vystup napiseme seznam jmenovatelu rozkladu oddelenych mezerou a znakem novy radek
#napr. pro vstup 1 2 bude vystup:
#vystup: 2
import math

x,y = input().split()
x = int(x)
y = int(y)

#print(math.ceil(y/x))


#pole = []
pole = []
while (True):
    print("nova iterace")
    pole.append(math.ceil(y/x))
    print(str(math.ceil(y/x)) + " tohle je ceil")
    print(str(-y % x ) + " tohle je modulo")
    
    temp_x = -y % x
    temp_y = y * (math.ceil(y/x))
    x = temp_x
    y = temp_y
    gcd = math.gcd(y,x)
    x = x // gcd
    y = y // gcd
    print(str(x) + " tohle je x")
    print(str(y) + " tohle je y")  
    if x == 1:
        pole.append(y)
        break
    
#chci vypsat pole s mezerama na jeden radek
print(*pole)


