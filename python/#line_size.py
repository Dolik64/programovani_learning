#line_size
#rows jsou radky
import random

def print_data(data):
    #print(data)
    pocet_radku = len(data[0])
    #print(pocet_radku)    10
    for i in range(pocet_radku):
        print(data[i])

def generate_data(sloupce, radky):
    return [[random.randint(0, 1) for i in range(sloupce)] for j in range(radky)]

def line_size(r, c, data):
    value = data[r][c]  # hodnota na pozici r, c
    size = 0  # velikost oblasti
    i = c  # index sloupce
    while i >= 0 and data[r][i] == value:
        size += 1
        i -= 1
    i = c + 1
    while i < len(data[r]) and data[r][i] == value:
        size += 1
        i += 1
    return size


seznam = generate_data(10, 10)
reg_size = line_size(5, 0, seznam)
print(reg_size)
print_data(seznam)