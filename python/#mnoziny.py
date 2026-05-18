#mnoziny

from xmlrpc.client import MAXINT


sousedi = [1, 2, 3, 4]
prekazky = []



"""
for element in sousedi:
    if element in prekazky:
        sousedi.remove(element)
    else:
        continue


print(sousedi)
"""

sousedni_prekazky = list(set(sousedi).intersection(prekazky))
sousedi = list(set(sousedi) - set(sousedni_prekazky))
#sousedi = sousedi - sousedni_prekazky
#print(sousedi)



x = 1.2563
y = MAXINT

if x<y:
    print("jirka")
