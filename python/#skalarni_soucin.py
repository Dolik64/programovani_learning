#skalarni_soucin
#dot product == skalarni soucin. vezmu vzdy nty prvek z vektoru, nasobim ntym prvkem druheho vektoru a pridam +
#import math je modul
#metoda
class MyVector:
    def __init__(self,prvky):   #definice konstruktoru, což je metoda v třídě
        self.prvky = prvky
    
    def get_vector(self):     #def je metoda
        return self.prvky
    
    def __mul__(self,other):     #mul se vola v případě přetížení operátoru *
        count = len(self.prvky)
        position = 0
        dot_product = 0
        for _ in range(count):
            dot_product += self.prvky[position] * other.prvky[position]
            position += 1
        return dot_product
    

"""""
if __name__ == '__main__':
    a = MyVector([1, 2, 3, 4])     # a, b jsou instance třídy MyVector
    b = MyVector([2, 3, 4, 5])
    print(a.get_vector())
    vysledek = a * b
    print(vysledek.prvky)
"""""

if __name__ == "__main__":
    vec1 = MyVector([1,2,3]) # vektory mohou byt i jine dimenze nez 3!
    vec2 = MyVector([3,4,5]) 
    print(vec1.get_vector()) # priklad ziskani seznamu
    dot_product = vec1*vec2  # vypocet skalarniho soucinu, pretizeny operator *, vola se __mul__
    print(dot_product)  
