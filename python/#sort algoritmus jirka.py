#sort algoritmus jirka
"""a = 5
li = [1, 2, 3]
[a] + li  # Don't use 'list' as variable name.
[5, 1, 2, 3]
"""
print("napis seznam cisel s mezerama")
vstup = input().split()
#print(seznam)
pocet_pozic = len(vstup)
mezipamet = 0
krok = 1
for i in range(pocet_pozic - 1):

    mezipamet = vstup[krok]
    vstup[krok] = vstup[krok -1]
    #break


    
print(vstup)
