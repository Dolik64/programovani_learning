#if defined



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
okno.geometry("1000x170")  # ",eogmetr = "20x20"

def mam_cislo():
    pass

cudlik1 = Button(okno, text="chci znát jméno", command=mam_cislo)
cudlik1.pack(side=tk.BOTTOM)
cudlik1.destroy()
cudlik1.destroy()
cudlik1.destroy()



thevariable = 0


"""
if x is None:
    print("promenna x neexistuje")
    """

try:
    thevariable
except NameError:
    print("well, it WASN'T defined after all!")
else:
    print("sure, it was defined.")



okno.mainloop()
