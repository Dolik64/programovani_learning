from email import message
from tkinter import *
import random
from tkinter import messagebox

import calendar


from datetime import date


from pathlib import Path

from tkinter import *

import tkinter as tk

from datetime import datetime

import os
# cislo = random.randint(14, 30)
# odber = cislo

okno = Tk()
okno.title("kalendar")
okno.geometry("1000x70")  # ",eogmetr = "20x20"


jmeno = []


datum_ciselne = date.today()
print(str(datum_ciselne))
str(datum_ciselne)
datum_tuning_den = str(datum_ciselne)[8] + str(datum_ciselne)[9]
datum_tuning_mesic = str(datum_ciselne)[5] + str(datum_ciselne)[6]
rok = (
    str(datum_ciselne)[0]
    + str(datum_ciselne)[1]
    + str(datum_ciselne)[2]
    + str(datum_ciselne)[3]
)


poradi_den = str(datum_tuning_den) + "."
if str(poradi_den)[0] == str(0):
    poradi_den = str(datum_tuning_den)[1] + "."


poradi_mesic = str(datum_tuning_mesic) + "."
if str(poradi_mesic)[0] == str(0):
    poradi_mesic = str(datum_tuning_mesic)[1] + "."


# dnes1 = Label(
"""
    okno,
    text="",
    fg="white",
    bg="red",
    font=("Comic Sans MS", 16),
    height=40,
    width=500,
    """
# )

# dnes1.pack()
# dnes.grid(row=5, column=1)


radek = []
pocet = 0

dokument = os.path.expanduser('~/Documents/Python/svatky_tuning.txt')


with open(dokument, encoding="utf8") as f:
    for line in f:
        radek.append(line.strip().split())
        # print(radek[0][1])
        if radek[0][0] == str(poradi_den) and radek[0][1] == str(poradi_mesic):
            pocet = len(radek[0])
            print("tohle je pocet  " + str(pocet))
            print("tohle je radek " + str(radek))
            if pocet == 5:
                jmeno.append(radek[0][pocet - 1])
            else:
                jmeno.append(radek[0][pocet - 1])
                jmeno.append("a")
                jmeno.append(radek[0][pocet - 3])

        # print(radek[0][0])
        radek.clear()


datum = Label(
    text="dnes je "
    + str(datum_tuning_den)
    + "."
    + str(datum_tuning_mesic)
    + " roku "
    + str(rok)
    + " a svátek má",
    font=("Comic Sans MS", 16),
)
datum.pack()


jmeno_label = Label(text=jmeno, font=("Comic Sans MS", 16))
jmeno_label.pack(side=tk.BOTTOM)


print("--------------")
print(jmeno)
print(poradi_den)
print(poradi_mesic)


print("--------------")


okno.mainloop()
