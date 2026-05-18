#power is key word in python, so we use pow instead of power
#I need to use power 4

# x = 0.51**4
# print(1-x)

# y = 0.49+0.51**1*0.49+0.51**2*0.49+0.51**3*0.49
# print(y)

#oba vysledky jsou stejne, ale prvni je rychlejsi

vzdalenost = 4200 - 800
#vzdalenost = 3400
start = 800
krok = 3400/6

for _ in range (6):
    start += krok
    print(start)