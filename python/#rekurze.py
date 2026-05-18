# rekurze

import sys


print("napiš jakékoliv čísla oddělené mezerou")
# funkce musí v tomto pripade mit argument

seznam = []
x = input()

while 5 != 3:

    if int(x) == -1:
        break

    else:
        seznam.append(x)
        x = input()

# seznam = x.split()
print(seznam)

"""
print("Enter/Paste your content. Ctrl-D or Ctrl-Z ( windows ) to save it.")
contents = []
while True:
    try:
        line = input()
    except EOFError:
        break
    contents.append(line)

        # break


    # print("x")

"""
soucet = 0
pocet_pozic = len(seznam) - 1


def rekurze():
    global soucet
    global pocet_pozic
    if pocet_pozic != -1:
        soucet = soucet + int(seznam[pocet_pozic])
        pocet_pozic = pocet_pozic - 1
        return rekurze()
    else:
        print("soucet je " + str(soucet))
        # break


if len(seznam) == 0:
    print("výsledek je 0")
# break
elif len(seznam) == 1:
    print("výsledek je " + str(seznam))
else:
    rekurze()
