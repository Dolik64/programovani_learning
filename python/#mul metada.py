#mul metada
import math


class Cislo:
    def __init__(self, hodnota):
        self.hodnota = hodnota
    """""
    def __mul__(self, other):
        nova_hodnota = self.hodnota * other.hodnota
        return Cislo(nova_hodnota)
    """""

    def __mul__(self, other):
        nova_hodnota = self.hodnota * other.hodnota
        return Cislo(nova_hodnota)

cislo1 = Cislo(5)       #objekt 
cislo2 = Cislo(3)

vysledek = cislo1 * cislo2  # Zavolá se metoda __mul__ na objektu cislo1
print(vysledek.hodnota)  # Výstup: 15s