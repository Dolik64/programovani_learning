# zavorky

with open("zavorky.txt", "r") as myfile:

    text = myfile.read().replace("\n", "")

# print(text)
#(x+3)/)(((5-6)*8) = 10


"""
seznam = text.split().strip()

print(seznam)
"""

zacatek_zavorky = 0
konec_zavorky = 0
krok = 0  # zacinam v nule takze len nesnizuji
vsechny = []


for i in range(len(text)):
    if text[krok] == "(":
        zacatek_zavorky = zacatek_zavorky + 1
        krok = krok + 1
        vsechny.append("(")
        # print(otevrena)
    elif text[krok] == ")":
        konec_zavorky = konec_zavorky + 1
        krok = krok + 1
        vsechny.append(")")
    else:
        krok = krok + 1



krok = len(vsechny) - 1
maximalni_pocet_zavorek = len(vsechny)/2
#logicke_uzavorkovani = []
print(vsechny)
chyba = 0


#logicke uzavorkovani nesmi obsahovat zavorku na konci prochazeni
# ze seznamu vsechny musi algo odstranit vzdy zavorku ktera byla zavrena, nakonec tam nic nezbyde


# print(zacatek_zavorky)
# print(konec_zavorky)
if zacatek_zavorky == konec_zavorky:
    krok = len(vsechny) - 1
    if vsechny[len(vsechny) - 1] == ")" and vsechny[0] == "(":




        for i in range (int(maximalni_pocet_zavorek)) :    #and chyba == 0

            #print(1)
            for j in range (len(vsechny)):
            #print(2)
                try:
                    if vsechny[krok] == "(":
    
                        del vsechny[krok]
                        try:
                            del vsechny[krok]
                            print(vsechny)
                            krok = len(vsechny) - 1
                            break
                        except IndexError:
            
                            chyba = 1
                            break
                    else:
                        krok = krok - 1
                except IndexError:
                    #chyba = 1
                    pass      
                
        

            

        #print("ano")
    else:
        #print("ne")
        chyba = 1
else:
    #print("ne")
    chyba = 1



if chyba == 0:
    print("ano")
else:
    print("ne")
