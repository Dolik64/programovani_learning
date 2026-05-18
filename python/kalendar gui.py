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

def passuju():
    pass

jmeno = []    #jmeno je seznam
overeni = 0
overeni2 = 0
uzivatel_seznam = []
datum_vypis = []




cudlik11 = Button(okno, text="chci znát jméno", command=passuju)
cudlik11.pack(side=tk.BOTTOM)
cudlik11.destroy()

cudlik22 = Button(okno, text="chci znát datum", command=passuju)
cudlik22.pack(side=tk.BOTTOM)
cudlik22.destroy()
eror_mam_jmeno = Label(text="zadal jsi spatne udaje")
eror_mam_jmeno.pack(side=tk.BOTTOM)
eror_mam_jmeno.destroy()

eror_mam_cislo = Label(text="zadal jsi spatne udaje")
eror_mam_cislo.pack(side=tk.BOTTOM)
eror_mam_cislo.destroy()
mam_cislo_entry = tk.Entry(okno)
mam_cislo_entry.pack(side=tk.BOTTOM)
mam_cislo_entry.destroy()
mam_jmeno_entry = tk.Entry(okno)
mam_jmeno_entry.pack(side=tk.BOTTOM)
mam_jmeno_entry.destroy()
potvrdit_mam_jmeno = Button(okno, text="potvrdit", command=passuju)
potvrdit_mam_jmeno.pack(side=tk.BOTTOM)
potvrdit_mam_jmeno.destroy()

potvrdit_mam_cislo = Button(okno, text="potvrdit", command=passuju)
potvrdit_mam_cislo.pack(side=tk.BOTTOM)
potvrdit_mam_cislo.destroy()


vypis_datumu1 = Label( text= " má svátek " )
vypis_datumu1.pack(side=tk.BOTTOM)
vypis_datumu1.destroy()

vypis_datumu2 = Label( text= " má svátek " )
vypis_datumu2.pack(side=tk.BOTTOM)
vypis_datumu2.destroy()

vypis_datumu3 = Label( text= " má svátek " )
vypis_datumu3.pack(side=tk.BOTTOM)
vypis_datumu3.destroy()


vypis_jmena = Label(text="tento den má svátek " )
vypis_jmena.pack(side=tk.BOTTOM)
vypis_jmena.destroy()

#cudlik22.destroy()


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


def zpet_def():
    print("zpet")
    global cudlik11
    global cudlik22
    global overeni
    global zpet
    global mam_cislo_entry
    global potvrdit_mam_cislo
    global zadej_cislo
    overeni = 1
    if overeni2 >= 1:

        vypis_jmena.destroy()
    cudlik11 = Button(okno, text="chci znát jméno", command=mam_cislo)
    cudlik11.pack(side=tk.BOTTOM)

    cudlik22 = Button(okno, text="chci znát datum", command=mam_jmeno)
    cudlik22.pack(side=tk.BOTTOM)
    uzivatel_seznam.clear()
    mam_cislo_entry.destroy()
    zadej_cislo.destroy()
    potvrdit_mam_cislo.destroy()
    zpet.destroy()
    eror_mam_jmeno.destroy()
    eror_mam_jmeno.destroy()
    eror_mam_cislo.destroy()
    mam_jmeno_entry.destroy()
    potvrdit_mam_jmeno.destroy()
    vypis_datumu1.destroy()
    vypis_datumu2.destroy()
    vypis_datumu3.destroy()
 

    pass


jmeno_label_comic = Label(text=jmeno, font=("Comic Sans MS", 16))
jmeno_label_comic.pack()


def mam_cislo():
    global mam_cislo
    global cudlik1
    global cudlik2
    global zpet
    global mam_cislo_entry
    global potvrdit_mam_cislo
    global zadej_cislo
    if overeni == 0:

        cudlik1.destroy()
        cudlik2.destroy()
    else:
        cudlik11.destroy()
        cudlik22.destroy()
    mam_cislo_entry = tk.Entry(okno)
    mam_cislo_entry.pack(side=tk.BOTTOM)
    zadej_cislo = Label(text="zadej den a číslo s tečkou a odděluj mezerou")
    zadej_cislo.pack(side=tk.BOTTOM)
    potvrdit_mam_cislo = Button(okno, text="potvrdit", command=potvrdit_mam_cislo_def)
    potvrdit_mam_cislo.pack(side=tk.BOTTOM)
    zpet = Button(okno, text="zpet na hlavni stranku", command=zpet_def)
    zpet.pack(side=tk.BOTTOM)
    pass


def potvrdit_mam_cislo_def():
    global eror_mam_cislo
    global fake_datum
    global vypis_jmena
    global uzivatel_seznam
    global overeni2
    uzivatel_datum = mam_cislo_entry.get()
    uzivatel_seznam.clear()
    
    if len(uzivatel_datum) != 0:

        uzivatel_seznam.append(uzivatel_datum.strip().split())
    print(uzivatel_seznam)
    # print(uzivatel_datum)
    jmeno.clear()
    with open(dokument, encoding="utf8") as f:
        for line in f:
            radek.append(line.strip().split())
            # print(radek[0][1])
            if len(uzivatel_datum) == 0:
                fake_datum = "A. B."
                uzivatel_seznam.append(fake_datum.strip().split())
                #print(uzivatel_seznam)

            #[['24.', '9.']]
            #print(uzivatel_seznam)    
            if radek[0][0] == str(uzivatel_seznam[0][0]) and radek[0][1] == str(
                uzivatel_seznam[0][1]
            ):
                pocet = len(radek[0])
                # print("tohle je pocet  " + str(pocet))
                # print("tohle je radek " + str(radek))
                if pocet == 5:
                    jmeno.append(radek[0][pocet - 1])
                    break
                else:
                    jmeno.append(radek[0][pocet - 1])
                    jmeno.append("a")
                    jmeno.append(radek[0][pocet - 3])
                    break

            # print(radek[0][0])
            radek.clear()

    # print(jmeno)
    if len(jmeno) == 0:
        zadej_cislo.destroy()
        potvrdit_mam_cislo.destroy()
        mam_cislo_entry.destroy()

        eror_mam_cislo = Label(text="zadal jsi spatne udaje")
        eror_mam_cislo.pack(side=tk.BOTTOM)
    else:
        zadej_cislo.destroy()
        potvrdit_mam_cislo.destroy()
        mam_cislo_entry.destroy()
        print(str(jmeno) + "300")


        if len(jmeno) == 1:
            overeni2 = 1
            vypis_jmena = Label(text="tento den má svátek " + str(jmeno[0]))
            vypis_jmena.pack(side=tk.BOTTOM)

        else:
            overeni2 = 1
            vypis_jmena = Label(
                text="tento den má svátek "
                + str(jmeno[0])
                + " "
                + str(jmeno[1])
                + " "
                + str(jmeno[2])
            )
            vypis_jmena.pack(side=tk.BOTTOM)
    jmeno.clear()
    pass






def mam_jmeno():
    global mam_jmeno
    global cudlik1
    global cudlik2
    global cudlik11
    global cudlik22
    global zpet
    global mam_jmeno_entry
    global potvrdit_mam_cislo
    global potvrdit_mam_jmeno
    global zadej_cislo
    if overeni == 0:

        cudlik1.destroy()
        cudlik2.destroy()
    else:
        cudlik11.destroy()
        cudlik22.destroy()
    mam_jmeno_entry = tk.Entry(okno)
    mam_jmeno_entry.pack(side=tk.BOTTOM)
    zadej_cislo = Label(text="zadej jméno s velým písmenem")
    zadej_cislo.pack(side=tk.BOTTOM)
    potvrdit_mam_jmeno = Button(okno, text="potvrdit", command=potvrdit_mam_jmeno_def)
    potvrdit_mam_jmeno.pack(side=tk.BOTTOM)
    zpet = Button(okno, text="zpet na hlavni stranku", command=zpet_def)
    zpet.pack(side=tk.BOTTOM)
    pass


def potvrdit_mam_jmeno_def():
    
    global datum_vypis
    global uzivatel_jmeno
    global eror_mam_jmeno
    global vypis_datumu1
    global vypis_datumu2
    global vypis_datumu3
    uzivatel_jmeno = mam_jmeno_entry.get()
    print(uzivatel_jmeno)
    mam_jmeno_entry.destroy()
    zadej_cislo.destroy()
    potvrdit_mam_jmeno.destroy()
    if len(uzivatel_jmeno) == 0:
        eror_mam_jmeno = Label(text="zadal jsi spatne udaje")
        eror_mam_jmeno.pack(side=tk.BOTTOM)
    #elif len(uzivatel_jmeno) <= 1:
       # eror_mam_jmeno = Label(text="zadal jsi spatne udaje")
      #  eror_mam_jmeno.pack(side=tk.BOTTOM)
    else:
        print("funguje")
        radek.clear()
        with open(dokument, encoding="utf8") as f:
            for line in f:
                radek.clear()
                radek.append(line.strip().split())
                #print(len(radek))
                if len(radek[0]) == 5:
                    #print(radek)
                    if uzivatel_jmeno == radek[0][4]:
                        print(radek)
                        print(radek[0][4])
                        datum_vypis.append(radek[0][0])
                        datum_vypis.append(radek[0][1])
                        vypis_datumu1 = Label( text= uzivatel_jmeno + " má svátek " + str(datum_vypis[0]) + " "+ str(datum_vypis[1]) + "    v1" )
                        vypis_datumu1.pack(side=tk.BOTTOM)
                        #datum_vypis.clear()
                        break
                   # else:
                     #   radek.clear()
                elif len(radek[0]) == 7:
                    if uzivatel_jmeno == radek[0][4]:
                        datum_vypis.append(radek[0][0])
                        datum_vypis.append(radek[0][1])
                        vypis_datumu2 = Label( text= uzivatel_jmeno + " má svátek " + str(datum_vypis[0]) + " "+ str(datum_vypis[1]) + "    v2" )
                        vypis_datumu2.pack(side=tk.BOTTOM)
                        print("elena prosla")
                        #datum_vypis.clear()
                        break

               # elif len(radek[0]) == 7:
                    #print("v3")
                    
                    else:
                        if uzivatel_jmeno == radek[0][6]:
                            datum_vypis.append(radek[0][0])
                            datum_vypis.append(radek[0][1])
                            vypis_datumu3 = Label( text= uzivatel_jmeno + " má svátek " + str(datum_vypis[0]) + " "+ str(datum_vypis[1]) + "      v3")
                            vypis_datumu3.pack(side=tk.BOTTOM)
                            print("pavel_prosel")
                        
                            break
                   # else:
                        #eror_mam_jmeno = Label(text="zadal jsi spatne udaje")
                        #eror_mam_jmeno.pack(side=tk.BOTTOM)
                        
                        #break
               # else:
                  #  radek.clear()
                    
        if len(datum_vypis) == 0:
            eror_mam_jmeno = Label(text="zadal jsi spatne udaje")
            eror_mam_jmeno.pack(side=tk.BOTTOM)
            datum_vypis.clear()
            radek.clear()
            
        datum_vypis.clear()
        jmeno.clear()
                        
    pass








cudlik1 = Button(okno, text="chci znát jméno", command=mam_cislo)
cudlik1.pack(side=tk.BOTTOM)


cudlik2 = Button(okno, text="chci znát datum", command=mam_jmeno)
cudlik2.pack(side=tk.BOTTOM)

print("--------------")
print(jmeno)
print(poradi_den)
print(poradi_mesic)


print("--------------")


okno.mainloop()
