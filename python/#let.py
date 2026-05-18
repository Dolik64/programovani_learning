#let

x = 1
y = 2
with let(x=3, z=4):
    x = 33
    y = 22
    z = 44
print(x, y, z)