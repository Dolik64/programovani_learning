#dvourozmerny seznam
# seznam ma 5 radku a 14 sloupcu    
import random

def print_data(data):
    seznam = data
    rows = len(seznam)
    columns = len(seznam[0])

    to_print = ""
    for rows in seznam:
        for columns in rows:
            to_print += str(columns) + " "
        to_print += "\n"

    print(to_print)

def generate_data(n_rows, n_columns):
    return [[random.randint(0, 1) for i in range(n_columns)] for j in range(n_rows)]

seznam = generate_data(5, 14)   #zde zadavam velikost matice
print(seznam)

print_data(seznam)
#print(data)