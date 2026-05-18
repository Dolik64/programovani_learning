#break

seznam = ['(', ')', '(', '(', ')', ')']
maximalni_pocet_zavorek = len(seznam)/2
#while len(seznam) nedavej tam while
krok = len(seznam) - 1

for i in range (int(maximalni_pocet_zavorek)):
    print(1)
    for j in range (int(maximalni_pocet_zavorek)):
        print(2)
        if 2<3:
            print(3)
            break


class GetOutOfLoop (Exception):
    pass

try:
    pass

except GetOutOfLoop:
    pass

#exeption je hovadina  ale uz to umim ovladat

#ty idiote, jakmile smazes pozici tak se na ni dostane jinej symbol

#co delat kdyz out of range