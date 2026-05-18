#seznam vypis
seznam = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
pozice = 0
x = 0
for i in range(10):
    #print(seznam[pozice])
    #pozice = pozice + 1
    #x = seznam[pozice]
    #if x == 5:
      #  print(x)
    #pozice = pozice + 1
    x = x + seznam[pozice]
    pozice = pozice + 1
print(x)
