A = int(input())
B = int(input())
for x in range (A,B):
    #print (x)
    podil = x
    while podil > 0:
        zbytek = podil % 10
        if zbytek == 4:
            print (x)
            break
        else:
            podil = podil // 10
            #print (podil)


print("naschle")