# morseovka
"""
for i in range 10:
        pass




"""
from pathlib import Path

from tkinter import *

import tkinter as tk


frame = tk.Tk()
frame.title("morseovka")
frame.geometry("400x400")

# vysledek bude seznam a kdystak s tim neco udelam

preklad = []

radek = []

vysledek = []

slovo_cesky = ""

pocet_cyklu = 0

pismeno = ""

lomitko = "/"


x = 0


def ziskat_text():
    global slovo_cesky
    global pocet_cyklu
    global x
    global pismeno
    global lomitko
    slovo_cesky = inputtxt.get(1.0, "end-1c")
    # print(slovo_cesky)
    pocet_cyklu = len(slovo_cesky)
    # print(pocet_cyklu)

    for i in range(pocet_cyklu):

        # print(pismeno)
        with open("morseovka.txt", encoding="utf8") as f:
            for line in f:
                pismeno = slovo_cesky[x]
                pismeno = pismeno.upper()
                radek.append(line.strip().split())
                if pismeno == radek[0][0]:
                    vysledek.append(radek[0][2])
                    vysledek.append(lomitko)

                radek.clear()
            x = x + 1
    # print(vysledek)
    lbl.config(text=vysledek)
    x = 0
    vysledek.clear()
    pass
    #  pass
    # pocet_cyklu = pocet_cyklu - 1

    pass


Button = tk.Button(
    frame, text="potvrdit", highlightbackground="#058ea7", command=ziskat_text
)
Button.grid(row=1, column=1)


inputtxt = tk.Text(frame, height=5, width=20)

inputtxt.grid(row=2, column=1)


lbl = tk.Label(
    frame,
    text=vysledek,
    font=("Arial", 22),
)
lbl.grid(row=3, column=1)


lbl_navod = tk.Label(
    frame,
    text="napis slovo cesky a ja ti ho prelozim do morseovky",
    fg="#099777",
    font=("Arial", 13),
)
lbl_navod.grid(row=4, column=1)

# slovo_cesky = inputtxt.get(1.0, "end-1c")


# f = open("morseovka.txt")

# print(preklad)

frame.mainloop()
