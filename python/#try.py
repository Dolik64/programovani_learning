#try
seznam = [1, 2, 3]
try:
    del seznam[4]
except IndexError:
    print("debile")

try:
    if seznam[4] == 4:
        print("0")
except IndexError:
    print("funguje")