#test slozka v pythnu

import os

seznam = []

dokument = os.path.expanduser('~/Documents/testpython.txt')

with open(dokument, encoding="utf8") as f:
    seznam = [line.strip() for line in f]


for i in range(100):
    print(seznam)