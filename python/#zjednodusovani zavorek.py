#zjednodusovani zavorek
#(x+3)/)(((5-6)*8) = 10
seznam = ['(', ')', '(', '(', ')', ')']
seznam = ['(', ')',")","(", '(', '(', ')', ')']
maximalni_pocet_zavorek = len(seznam)/2
#while len(seznam) nedavej tam while
krok = len(seznam) - 1

#pozor zavorka do dvojice je vzdy v prvo od leve zavorky


#class GetOutOfLoop (Exception):
    #pass

#print(maximalni_pocet_zavorek)
print(seznam)
chyba = 0

for i in range (int(maximalni_pocet_zavorek)) :    #and chyba == 0

    #print(1)
    for j in range (len(seznam)):
        #print(2)
        try:
            if seznam[krok] == "(":
    
                del seznam[krok]
                try:
                    del seznam[krok]
                    print(seznam)
                    krok = len(seznam) - 1
                    break
                except IndexError:
            
                    chyba = 1
                    break
            else:
                krok = krok - 1
        except IndexError:
            pass      
        

if chyba == 0:
    print("ano")
else:
    print("ne")

#print(seznam)


