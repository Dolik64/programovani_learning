#vypis cislice
print("napis cislici")
x = int(input())
kolik_ma_znaku = len(str(x))
num = kolik_ma_znaku
#print(kolik_ma_znaku)
odecet = 0
for i in range(num):
    
    pozice = (kolik_ma_znaku - 1) - odecet
    text = "tvoje cislo obsahuje cislici: "
    print (text + str(x)[pozice])
    #print("mezera")
    #print (str(x)[1])
    #pozice = pozice - 1
    odecet = odecet + 1
