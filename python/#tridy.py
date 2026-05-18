#tridy

import math

class ComplexNumber:
    def __init__(self, re, im):
        self.re = re
        self.im = im

    def to_string(self):
        return f"{self.re}+{self.im}i"

    def size(self):
        return math.sqrt (self.re**2 + self.im**2)
    
    def inkrement(self, other):
        self.im += other.im
        self.re += other.re
    
if __name__ == '__main__':
    a = ComplexNumber(4,5)
    b = ComplexNumber(3,3)

    """""
    print(a.re)
    print(a.im)

    print(b.re)
    print(b.im)
    """""
    print(a.to_string())
    a.inkrement(b)
    print(a.to_string())
    print(a.size())
