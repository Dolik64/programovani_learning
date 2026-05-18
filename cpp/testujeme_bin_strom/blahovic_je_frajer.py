import math

x,y = input().split()
x = int(x)
y = int(y)

pole = []

if x == 1:
    pole.append(y)
    print(*pole)
else:
    while (True):
        pole.append(math.ceil(y/x))
        
        temp_x = -y % x
        temp_y = y * (math.ceil(y/x))
        x = temp_x
        y = temp_y
        gcd = math.gcd(y,x)
        x = x // gcd
        y = y // gcd
    
        if x == 1:
            pole.append(y)
            break
    
    print(*pole)


