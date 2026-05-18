#prevod do jine soustavy

list = []

print("vychazime z desitkove soustavy")
print("zadej cislo")
cislo = int(input())
print("zadej soustavu")
soustava = int(input())

while cislo !=0:
  #  cislo/soustava 
  modulo = cislo%soustava 
  modulo = int(modulo)

  list.append(modulo)
  cislo = cislo - modulo
  cislo = cislo/soustava

#print(list)

pozice = len(list)
krok = pozice - 1
string = ""
for i in range(pozice):
  string = string +str(list[krok])
  krok = krok - 1

print(string)