#config


from tkinter import *

import random

from tkinter import messagebox


okno = Tk()

okno.title("Kalkulacka")

okno.geometry("1100x800")

navod4 = Label(okno, text = "tvovu")
navod4.grid(row=7, column=1)


def debil():

    navod4.config(text = "tvoje slovo neni v seznamu, zkus to znovu")
    


cudlik = Button(okno, text = "zmackni", command = debil)
cudlik.grid(row=1, column=1)

okno.mainloop()
