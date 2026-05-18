# hledani kilometru 3

# sli jsme 888 km.
# Sli jsme 9 km ze Svetle na Lipnici a pak jeste 1 km k lomu. A pak ještě 3 dny, ale to už bylo jen 5 km daleko.


with open("cesta.txt", "r") as myfile:
    string = myfile.read().replace("\n", "")

print(string)


slova_dohromady = []
slovo = ""
delka_strinku = len(string)
krok = 0
vysledek = 0
test = 0
mezera = ""


for i in range(delka_strinku):
    if string[krok] == " ":
        slova_dohromady.append(slovo)
        slovo = ""
        krok = krok + 1
    else:
        slovo = slovo + string[krok]
        krok = krok + 1

slovo = ""

while mezera != " ":
    mezera = string[delka_strinku - 1]
    slovo = slovo + string[delka_strinku - 1]
    delka_strinku = delka_strinku - 1

slovo = slovo[::-1]
slova_dohromady.append(slovo)
    

print(slova_dohromady)

delka_seznamu = len(slova_dohromady)
#print(delka_seznamu)
krok = 0
for l in range(delka_seznamu):
    if slova_dohromady[krok] == "km":
        vysledek = vysledek + int(slova_dohromady[krok - 1])
        test = test + 1
        krok = krok + 1
    elif slova_dohromady[krok] == " km.":
        vysledek = vysledek + int(slova_dohromady[krok - 1])
        test = test + 1
        krok = krok + 1
    else:
        krok = krok + 1
        test = test + 1

print("")
print("soucet kilometru je " + str(vysledek))
print("")
#print(test)
