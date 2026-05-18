#config test

from tkinter import *
import random
from tkinter import messagebox

okno = Tk()
okno.title('Kalkulacka')
okno.geometry("700x700")

test = "jirka"
jarmil = "jarmil"

def config():
    global jarmil
    label.config(text= jarmil, font=("Arial", 36))
    #label.grid(row=2, column=1)

cudlik = Button(okno, text="zmackni me", command = config)
cudlik.grid(row=1, column=1)

label = Label(okno, text= test, font=("Arial", 36))
label.grid(row=2, column=1)

okno.mainloop()
