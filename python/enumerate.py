""""
for i in enumerate (5):
    print("ahoj")
"""""

seznam = [1, 2, 3, 4, 5, 6, 7, 8, 9]
i = 0
max = seznam[i]

def find_max():
    seznam = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    i = 0
    max = seznam[i]
    for i in range(len(seznam)):
        #print (max)
        if seznam[i] > max:
            max = int(seznam[i])
    print(max)
find_max()