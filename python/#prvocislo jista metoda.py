#prvocislo jista metoda
print("napis cislo")
x = int(input())
pravda = 0
budu_odcitat = x - 1
while budu_odcitat > 2:
    retezec = x / budu_odcitat
    str(retezec)
    pocet_cifer = len(retezec) 
    if retezec[pocet_cifer - 1] == 0:
        print("cislo neni prvocislo")
        pravda = 1
        break
    else:
        float(retezec)
        budu_odcitat = budu_odcitat - 1
if pravda == 0:
    print("je to prvocislo")
