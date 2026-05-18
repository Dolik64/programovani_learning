# prekladac aka Jirka      (os.path.expanduser

from pathlib import Path

from tkinter import *

import tkinter as tk

frame = tk.Tk()
frame.title("prekladac")
frame.geometry('800x400')





radek = []


neumis_psat = []


vysledek = []

ceske_slova = []

overeni = 0

zadani_jazyka = 0

print()

# print("chces tvoje slovo cesky?")
f = open("prekladac.txt")
for line in f:
    radek.append(line.strip().split())
    ceske_slova.append(radek[0][0])
    radek.clear()

lbl = tk.Label(frame, text = ceske_slova, fg="#099777", font=("Arial", 22),)
lbl.grid(row=1, column=1)

navod1 = tk.Label(frame, text = "napis slovo ze seznamu")
navod1.grid(row=2, column=1)


mezera = tk.Label(frame, text = "                   ")
mezera.grid(row=3, column=1)



inputtxt = tk.Text(frame,
                   height = 5,
                   width = 20)
  
inputtxt.grid(row=4, column=1)


navod4 = tk.Label(frame, text = "")
navod4.grid(row=7, column=1)


navod5 = tk.Label(frame, text = "")
navod5.grid(row=8, column=1)

navod6 = tk.Label(frame, text = "", fg="#099777", font=("Arial", 22),)
navod6.grid(row=9, column=1)


def ziskat_text():
    global overeni
    global slovo_cesky
    global f
    slovo_cesky = inputtxt.get(1.0, "end-1c")
    vysledek.clear()
    radek.clear()
    overeni = 0




    
    f = open("prekladac.txt")
    for line in f:
        radek.append(line.strip().split())
        if radek[0][0] == slovo_cesky:
            vysledek.append(radek[0][1])
            vysledek.append(radek[0][2])
            overeni = 1
            navod4.config(text = "")
            navod5.config(text = "zmackni jedno z ruzovych tlacitek")
            neumis_psat.clear()

            #  print("jarmil")
            break
        radek.clear()
    if overeni == 0:
        navod4.config(text = "tvoje slovo neni v seznamu, zkus to znovu")
        navod5.config(text = "")
        navod6.config(text = "")
        neumis_psat.append(1)

    if len(neumis_psat) == 0:
        navod4.config(text = "")


"""
        if overeni == 0:
            navod4.config(text = "tvoje slovo neni v seznamu, zkus to znovu")
            #navod4.grid(row=7, column=1)
            #print("tvoje slovo neni v seznamu, zkus to znovu")
            slovo_cesky = inputtxt.get(1.0, "end-1c")
"""

            #(frame, text = "")
   # pass

Button = tk.Button(frame,
                        text = "potvrdit", highlightbackground="#058ea7",
                        command = ziskat_text)
Button.grid(row=5, column=1)



def anglicky():
    navod6.config(text = vysledek[0])
    pass


def francouzsky():
    navod6.config(text = vysledek[1])
    pass


Button = tk.Button(frame,
                        text = "anglicky",background="orange",highlightbackground="#ff00c0",
                        command = anglicky)
Button.grid(row=6, column=1)



Button = tk.Button(frame,
                        text = "francouzsky", background="orange",highlightbackground="#ff00c0",
                        command = francouzsky)
Button.grid(row=6, column=2)







frame.mainloop()
