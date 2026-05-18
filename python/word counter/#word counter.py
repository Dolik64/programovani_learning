#word counter


vse = []
f = open("word_counter.txt")
x = f.read()
#print(x)
pocet = x.strip().split()

print("pocet slov")
print(len(pocet))
