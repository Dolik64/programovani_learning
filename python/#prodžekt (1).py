# prodžekt

from tkinter import *

import random

from tkinter import messagebox


okno = Tk()

okno.title("Kalkulacka")

okno.geometry("1100x800")


pozice = []

overeni_zacina_cislo = []

plus_minus = []

mackas_vic_znamenek = []


druhamocnina = 0

cislo_prvni = ""

znamenko = ""

cislo_druhe = ""

rovnase = "="

vysledek = ""

test = "test"

mez = " "

matematicky_vysledek = 0

matematicke_prvni = 0

matematicke_druhe = 0

# mezera nazev je moc dlouhej


string = cislo_prvni + znamenko + cislo_druhe + rovnase + vysledek


def plus():

    if True:

        global znamenko

        if len(overeni_zacina_cislo) == 0:

            messagebox.showinfo("nejdriv zadej cislo", "nejdriv zadej cislo")

        else:

            if len(mackas_vic_znamenek) == 0:

                mackas_vic_znamenek.append(1)

                if len(plus_minus) == 0:

                    plus_minus.append(1)

                if len(pozice) == 0:

                    pozice.append(1)

                znamenko = "+"

                stav.config(
                    text=cislo_prvni
                    + mez
                    + znamenko
                    + mez
                    + cislo_druhe
                    + mez
                    + rovnase
                    + mez
                    + vysledek,
                    font=("Arial", 36),
                )

            else:

                messagebox.showinfo(
                    "uz si jednou zmacnul znaminko",
                    "uz si jednou zmacnul znaminko, bud dokonci vypocet a nebo vynuluj kalkulacku",
                )

        #   stav.grid(row=3,column=2)


def deleno():

    if True:

        global znamenko

        if len(overeni_zacina_cislo) == 0:

            messagebox.showinfo("nejdriv zadej cislo", "nejdriv zadej cislo")

        else:

            if len(mackas_vic_znamenek) == 0:

                mackas_vic_znamenek.append(1)

                if len(plus_minus) == 0:

                    plus_minus.append(2)

                if len(pozice) == 0:

                    pozice.append(1)

                znamenko = "/"

                stav.config(
                    text=cislo_prvni
                    + mez
                    + znamenko
                    + mez
                    + cislo_druhe
                    + mez
                    + rovnase
                    + mez
                    + vysledek,
                    font=("Arial", 36),
                )

            else:

                messagebox.showinfo(
                    "uz si jednou zmacnul znaminko",
                    "uz si jednou zmacnul znaminko, bud dokonci vypocet a nebo vynuluj kalkulacku",
                )

        #   stav.grid(row=3,column=2)

    pass


def minus():

    if True:

        global znamenko

        if len(overeni_zacina_cislo) == 0:

            messagebox.showinfo("nejdriv zadej cislo", "nejdriv zadej cislo")

        else:

            if len(mackas_vic_znamenek) == 0:

                mackas_vic_znamenek.append(1)

                if len(plus_minus) == 0:

                    plus_minus.append(3)

                if len(pozice) == 0:

                    pozice.append(1)

                znamenko = "-"

                stav.config(
                    text=cislo_prvni
                    + mez
                    + znamenko
                    + mez
                    + cislo_druhe
                    + mez
                    + rovnase
                    + mez
                    + vysledek,
                    font=("Arial", 36),
                )

            else:

                messagebox.showinfo(
                    "uz si jednou zmacnul znaminko",
                    "uz si jednou zmacnul znaminko, bud dokonci vypocet a nebo vynuluj kalkulacku",
                )

        #   stav.grid(row=3,column=2)


def nadruhou():

    if True:

        global cislo_prvni
        global druhamocnina
        global cislo_druhe
        global matematicke_prvni
        global matematicke_druhe

        if cislo_prvni == "":
            messagebox.showinfo("nejdriv zadej cislo", "nejdriv zadej cislo")
        elif cislo_druhe == "":
            int(cislo_prvni)
            druhamocnina = int(cislo_prvni) * int(cislo_prvni)
            cislo_prvni = str(druhamocnina)
            str(cislo_prvni)
            print(cislo_prvni)

            stav.config(
                text=cislo_prvni
                + mez
                + znamenko
                + mez
                + cislo_druhe
                + mez
                + rovnase
                + mez
                + vysledek,
                font=("Arial", 36),
            )
            matematicke_prvni = int(cislo_prvni)
        else:
            druhamocnina = 0
            int(cislo_druhe)
            druhamocnina = int(cislo_druhe) * int(cislo_druhe)
            cislo_druhe = str(druhamocnina)
            str(cislo_druhe)
            # print(cislo_prvni)

            stav.config(
                text=cislo_prvni
                + mez
                + znamenko
                + mez
                + cislo_druhe
                + mez
                + rovnase
                + mez
                + vysledek,
                font=("Arial", 36),
            )
            matematicke_druhe = int(cislo_druhe)


def jedna():

    if True:

        global cislo_prvni

        global test

        global znamenko

        global cislo_druhe

        global rovnase

        global vysledek

        global matematicke_prvni

        global matematicke_druhe

        if len(pozice) == 0:

            if len(overeni_zacina_cislo) == 0:

                overeni_zacina_cislo.append(1)

            cislo_prvni = cislo_prvni + "1"

            matematicke_prvni = int(cislo_prvni)

            str(cislo_prvni)

            stav.config(
                text=cislo_prvni
                + mez
                + znamenko
                + mez
                + cislo_druhe
                + mez
                + rovnase
                + mez
                + vysledek,
                font=("Arial", 36),
            )

        #  stav.grid(row=3,column=2)

        # print(string)

        #  print(cislo_prvni)

        elif len(pozice) == 1:

            cislo_druhe = cislo_druhe + "1"

            matematicke_druhe = int(cislo_druhe)

            str(cislo_druhe)

            stav.config(
                text=cislo_prvni
                + mez
                + znamenko
                + mez
                + cislo_druhe
                + mez
                + rovnase
                + mez
                + vysledek,
                font=("Arial", 36),
            )

        #  stav.grid(row=3,column=2)


# pass


def krat():

    if True:

        global znamenko

        if len(overeni_zacina_cislo) == 0:

            messagebox.showinfo("nejdriv zadej cislo", "nejdriv zadej cislo")

        else:

            if len(mackas_vic_znamenek) == 0:

                mackas_vic_znamenek.append(1)

                if len(plus_minus) == 0:

                    plus_minus.append(4)

                if len(pozice) == 0:

                    pozice.append(1)

                znamenko = "x"

                stav.config(
                    text=cislo_prvni
                    + mez
                    + znamenko
                    + mez
                    + cislo_druhe
                    + mez
                    + rovnase
                    + mez
                    + vysledek,
                    font=("Arial", 36),
                )

            else:

                messagebox.showinfo(
                    "uz si jednou zmacnul znaminko",
                    "uz si jednou zmacnul znaminko, bud dokonci vypocet a nebo vynuluj kalkulacku",
                )

        #   stav.grid(row=3,column=2)


def tri():

    if True:

        global cislo_prvni

        global test

        global znamenko

        global cislo_druhe

        global rovnase

        global vysledek

        global matematicke_prvni

        global matematicke_druhe

        if len(pozice) == 0:

            if len(overeni_zacina_cislo) == 0:

                overeni_zacina_cislo.append(1)

            cislo_prvni = cislo_prvni + "3"

            matematicke_prvni = int(cislo_prvni)

            str(cislo_prvni)

            stav.config(
                text=cislo_prvni
                + mez
                + znamenko
                + mez
                + cislo_druhe
                + mez
                + rovnase
                + mez
                + vysledek,
                font=("Arial", 36),
            )

        #    stav.grid(row=3,column=2)

        # print(string)

        #  print(cislo_prvni)

        elif len(pozice) == 1:

            cislo_druhe = cislo_druhe + "3"

            matematicke_druhe = int(cislo_druhe)

            str(cislo_druhe)

            stav.config(
                text=cislo_prvni
                + mez
                + znamenko
                + mez
                + cislo_druhe
                + mez
                + rovnase
                + mez
                + vysledek,
                font=("Arial", 36),
            )

        #   stav.grid(row=3,column=2)


def dva():

    if True:

        global cislo_prvni

        global test

        global znamenko

        global cislo_druhe

        global rovnase

        global vysledek

        global matematicke_prvni

        global matematicke_druhe

        if len(pozice) == 0:

            if len(overeni_zacina_cislo) == 0:

                overeni_zacina_cislo.append(1)

            cislo_prvni = cislo_prvni + "2"

            matematicke_prvni = int(cislo_prvni)

            str(cislo_prvni)

            stav.config(
                text=cislo_prvni
                + mez
                + znamenko
                + mez
                + cislo_druhe
                + mez
                + rovnase
                + mez
                + vysledek,
                font=("Arial", 36),
            )

        #   stav.grid(row=3,column=2)

        # print(string)

        #  print(cislo_prvni)

        elif len(pozice) == 1:

            cislo_druhe = cislo_druhe + "2"

            matematicke_druhe = int(cislo_druhe)

            str(cislo_druhe)

            stav.config(
                text=cislo_prvni
                + mez
                + znamenko
                + mez
                + cislo_druhe
                + mez
                + rovnase
                + mez
                + vysledek,
                font=("Arial", 36),
            )

        # stav.grid(row=3,column=2)


def ctyri():

    if True:

        global cislo_prvni

        global test

        global znamenko

        global cislo_druhe

        global rovnase

        global vysledek

        global matematicke_prvni

        global matematicke_druhe

        if len(pozice) == 0:

            if len(overeni_zacina_cislo) == 0:

                overeni_zacina_cislo.append(1)

            cislo_prvni = cislo_prvni + "4"

            matematicke_prvni = int(cislo_prvni)

            str(cislo_prvni)

            stav.config(
                text=cislo_prvni
                + mez
                + znamenko
                + mez
                + cislo_druhe
                + mez
                + rovnase
                + mez
                + vysledek,
                font=("Arial", 36),
            )

        #  stav.grid(row=3,column=2)

        # print(string)

        #  print(cislo_prvni)

        elif len(pozice) == 1:

            cislo_druhe = cislo_druhe + "4"

            matematicke_druhe = int(cislo_druhe)

            str(cislo_druhe)

            stav.config(
                text=cislo_prvni
                + mez
                + znamenko
                + mez
                + cislo_druhe
                + mez
                + rovnase
                + mez
                + vysledek,
                font=("Arial", 36),
            )

        #  stav.grid(row=3,column=2)


def sedm():

    if True:

        global cislo_prvni

        global test

        global znamenko

        global cislo_druhe

        global rovnase

        global vysledek

        global matematicke_prvni

        global matematicke_druhe

        if len(pozice) == 0:

            if len(overeni_zacina_cislo) == 0:

                overeni_zacina_cislo.append(1)

            cislo_prvni = cislo_prvni + "7"

            matematicke_prvni = int(cislo_prvni)

            str(cislo_prvni)

            stav.config(
                text=cislo_prvni
                + mez
                + znamenko
                + mez
                + cislo_druhe
                + mez
                + rovnase
                + mez
                + vysledek,
                font=("Arial", 36),
            )

        #  stav.grid(row=3,column=2)

        # print(string)

        #  print(cislo_prvni)

        elif len(pozice) == 1:

            cislo_druhe = cislo_druhe + "7"

            matematicke_druhe = int(cislo_druhe)

            str(cislo_druhe)

            stav.config(
                text=cislo_prvni
                + mez
                + znamenko
                + mez
                + cislo_druhe
                + mez
                + rovnase
                + mez
                + vysledek,
                font=("Arial", 36),
            )

        #   stav.grid(row=3,column=2)


def pet():

    if True:

        global cislo_prvni

        global test

        global znamenko

        global cislo_druhe

        global rovnase

        global vysledek

        global matematicke_prvni

        global matematicke_druhe

        if len(pozice) == 0:

            if len(overeni_zacina_cislo) == 0:

                overeni_zacina_cislo.append(1)

            cislo_prvni = cislo_prvni + "5"

            matematicke_prvni = int(cislo_prvni)

            str(cislo_prvni)

            stav.config(
                text=cislo_prvni
                + mez
                + znamenko
                + mez
                + cislo_druhe
                + mez
                + rovnase
                + mez
                + vysledek,
                font=("Arial", 36),
            )

        #  stav.grid(row=3,column=2)

        # print(string)

        #  print(cislo_prvni)

        elif len(pozice) == 1:

            cislo_druhe = cislo_druhe + "5"

            matematicke_druhe = int(cislo_druhe)

            str(cislo_druhe)

            stav.config(
                text=cislo_prvni
                + mez
                + znamenko
                + mez
                + cislo_druhe
                + mez
                + rovnase
                + mez
                + vysledek,
                font=("Arial", 36),
            )

        #   stav.grid(row=3,column=2)


def sest():

    if True:

        global cislo_prvni

        global test

        global znamenko

        global cislo_druhe

        global rovnase

        global vysledek

        global matematicke_prvni

        global matematicke_druhe

        if len(pozice) == 0:

            if len(overeni_zacina_cislo) == 0:

                overeni_zacina_cislo.append(1)

            cislo_prvni = cislo_prvni + "6"

            matematicke_prvni = int(cislo_prvni)

            str(cislo_prvni)

            stav.config(
                text=cislo_prvni
                + mez
                + znamenko
                + mez
                + cislo_druhe
                + mez
                + rovnase
                + mez
                + vysledek,
                font=("Arial", 36),
            )

        #  stav.grid(row=3,column=2)

        # print(string)

        #  print(cislo_prvni)

        elif len(pozice) == 1:

            cislo_druhe = cislo_druhe + "6"

            matematicke_druhe = int(cislo_druhe)

            str(cislo_druhe)

            stav.config(
                text=cislo_prvni
                + mez
                + znamenko
                + mez
                + cislo_druhe
                + mez
                + rovnase
                + mez
                + vysledek,
                font=("Arial", 36),
            )


def nula():

    if True:

        global cislo_prvni

        global test

        global znamenko

        global cislo_druhe

        global rovnase

        global vysledek

        global matematicke_prvni

        global matematicke_druhe

        if len(pozice) == 0:

            if len(overeni_zacina_cislo) == 0:

                overeni_zacina_cislo.append(1)

            cislo_prvni = cislo_prvni + "0"

            matematicke_prvni = int(cislo_prvni)

            str(cislo_prvni)

            stav.config(
                text=cislo_prvni
                + mez
                + znamenko
                + mez
                + cislo_druhe
                + mez
                + rovnase
                + mez
                + vysledek,
                font=("Arial", 36),
            )
        elif len(pozice) == 1:

            cislo_druhe = cislo_druhe + "0"

            matematicke_druhe = int(cislo_druhe)

            str(cislo_druhe)

            stav.config(
                text=cislo_prvni
                + mez
                + znamenko
                + mez
                + cislo_druhe
                + mez
                + rovnase
                + mez
                + vysledek,
                font=("Arial", 36),
            )

        #  stav.grid(row=3,column=2)

        # print(string)

        #  print(cislo_prvni)

        elif len(pozice) == 1:

            cislo_druhe = cislo_druhe + "6"

            matematicke_druhe = int(cislo_druhe)

            str(cislo_druhe)

            stav.config(
                text=cislo_prvni
                + mez
                + znamenko
                + mez
                + cislo_druhe
                + mez
                + rovnase
                + mez
                + vysledek,
                font=("Arial", 36),
            )

        #   stav.grid(row=3,column=2)


def devet():

    if True:

        global cislo_prvni

        global test

        global znamenko

        global cislo_druhe

        global rovnase

        global vysledek

        global matematicke_prvni

        global matematicke_druhe

        if len(pozice) == 0:

            if len(overeni_zacina_cislo) == 0:

                overeni_zacina_cislo.append(1)

            cislo_prvni = cislo_prvni + "9"

            matematicke_prvni = int(cislo_prvni)

            str(cislo_prvni)

            stav.config(
                text=cislo_prvni
                + mez
                + znamenko
                + mez
                + cislo_druhe
                + mez
                + rovnase
                + mez
                + vysledek,
                font=("Arial", 36),
            )

        #  stav.grid(row=3,column=2)

        # print(string)

        #  print(cislo_prvni)

        elif len(pozice) == 1:

            cislo_druhe = cislo_druhe + "9"

            matematicke_druhe = int(cislo_druhe)

            str(cislo_druhe)

            stav.config(
                text=cislo_prvni
                + mez
                + znamenko
                + mez
                + cislo_druhe
                + mez
                + rovnase
                + mez
                + vysledek,
                font=("Arial", 36),
            )

        #   stav.grid(row=3,column=2)


def osm():

    if True:

        global cislo_prvni

        global test

        global znamenko

        global cislo_druhe

        global rovnase

        global vysledek

        global matematicke_prvni

        global matematicke_druhe

        if len(pozice) == 0:

            if len(overeni_zacina_cislo) == 0:

                overeni_zacina_cislo.append(1)

            cislo_prvni = cislo_prvni + "8"

            matematicke_prvni = int(cislo_prvni)

            str(cislo_prvni)

            stav.config(
                text=cislo_prvni
                + mez
                + znamenko
                + mez
                + cislo_druhe
                + mez
                + rovnase
                + mez
                + vysledek,
                font=("Arial", 36),
            )

        #  stav.grid(row=3,column=2)

        # print(string)

        #  print(cislo_prvni)

        elif len(pozice) == 1:

            cislo_druhe = cislo_druhe + "8"

            matematicke_druhe = int(cislo_druhe)

            str(cislo_druhe)

            stav.config(
                text=cislo_prvni
                + mez
                + znamenko
                + mez
                + cislo_druhe
                + mez
                + rovnase
                + mez
                + vysledek,
                font=("Arial", 36),
            )

        #   stav.grid(row=3,column=2)


def vynulovat():

    global cislo_prvni

    global test

    global znamenko

    global cislo_druhe

    global rovnase

    global vysledek

    global matematicke_prvni

    global matematicke_druhe

    global matematicky_vysledek

    global delete

    global l

    global p

    global k

    global cyklus
    global druhamocnina

    druhamocnina = 0

    delete = len(pozice)

    cyklus = delete

    for l in range(cyklus):

        del pozice[delete - 1]

        delete = delete - 1

    print("seznamy")

    print(len(pozice))

    delete = len(overeni_zacina_cislo)

    cyklus = delete

    for p in range(cyklus):

        del overeni_zacina_cislo[delete - 1]

        delete = delete - 1

    print(len(overeni_zacina_cislo))

    delete = len(plus_minus)

    cyklus = delete

    for k in range(cyklus):

        del plus_minus[delete - 1]

        delete = delete - 1

    print(len(plus_minus))

    print("seznamy")

    delete = len(mackas_vic_znamenek)

    cyklus = delete

    for k in range(cyklus):

        del mackas_vic_znamenek[delete - 1]

        delete = delete - 1

    cislo_prvni = ""

    znamenko = ""

    cislo_druhe = ""

    rovnase = "="

    vysledek = ""

    test = "test"

    matematicky_vysledek = 0

    matematicke_prvni = 0

    matematicke_druhe = 0

    stav.config(
        text=cislo_prvni
        + mez
        + znamenko
        + mez
        + cislo_druhe
        + mez
        + rovnase
        + mez
        + vysledek,
        font=("Arial", 36),
    )

    # stav.grid(row=3,column=2)

    pass


def rovnase_funkce():

    global matematicky_vysledek

    # global matematicke_druhe

    if plus_minus[0] == 1:

        matematicky_vysledek = matematicke_prvni + matematicke_druhe

        print(matematicky_vysledek)

    elif plus_minus[0] == 2:

        matematicky_vysledek = matematicke_prvni / matematicke_druhe

    elif plus_minus[0] == 3:

        matematicky_vysledek = matematicke_prvni - matematicke_druhe

    elif plus_minus[0] == 4:

        matematicky_vysledek = matematicke_prvni * matematicke_druhe
    # else:
    #   matematicky_vysledek = cislo_prvni

    vysledek = str(matematicky_vysledek)

    stav.config(
        text=cislo_prvni
        + mez
        + znamenko
        + mez
        + cislo_druhe
        + mez
        + rovnase
        + mez
        + vysledek,
        font=("Arial", 36),
    )


#  stav.grid(row=5,column=2)


krat_tlacitko = Button(
    okno,
    width="10",
    height="5",
    background="orange",
    text="x",
    font=("Arial", 22),
    command=krat,
)

# jedna_tlacitko.config()

krat_tlacitko.grid(row=1, column=1)


deleno_tlacitko = Button(
    okno,
    width="10",
    height="5",
    background="orange",
    text="/",
    font=("Arial", 22),
    command=deleno,
)

# jedna_tlacitko.config()

deleno_tlacitko.grid(row=5, column=1)


jedna_tlacitko = Button(
    okno,
    width="10",
    height="5",
    background="orange",
    text="1",
    font=("Arial", 22),
    command=jedna,
)

# jedna_tlacitko.config()


nula_tlacitko = Button(
    okno,
    width="10",
    height="5",
    background="orange",
    text="0",
    font=("Arial", 22),
    command=nula,
)
nula_tlacitko.grid(row=2, column=4)

# jedna_tlacitko.config()

jedna_tlacitko.grid(row=2, column=1)


dva_tlacitko = Button(
    okno,
    width="10",
    height="5",
    background="orange",
    text="2",
    font=("Arial", 22),
    command=dva,
)

# jedna_tlacitko.config()

dva_tlacitko.grid(row=2, column=2)


tri_tlacitko = Button(
    okno,
    width="10",
    height="5",
    background="orange",
    text="3",
    font=("Arial", 22),
    command=tri,
)

# jedna_tlacitko.config()

tri_tlacitko.grid(row=2, column=3)


ctyri_tlacitko = Button(
    okno,
    width="10",
    height="5",
    background="orange",
    text="4",
    font=("Arial", 22),
    command=ctyri,
)

# jedna_tlacitko.config()

ctyri_tlacitko.grid(row=3, column=1)


sedm_tlacitko = Button(
    okno,
    width="10",
    height="5",
    background="orange",
    text="7",
    font=("Arial", 22),
    command=sedm,
)

# jedna_tlacitko.config()

sedm_tlacitko.grid(row=4, column=1)


pet_tlacitko = Button(
    okno,
    width="10",
    height="5",
    background="orange",
    text="5",
    font=("Arial", 22),
    command=pet,
)

# jedna_tlacitko.config()

pet_tlacitko.grid(row=3, column=2)


sest_tlacitko = Button(
    okno,
    width="10",
    height="5",
    background="orange",
    text="6",
    font=("Arial", 22),
    command=sest,
)

# jedna_tlacitko.config()

sest_tlacitko.grid(row=3, column=3)


devet_tlacitko = Button(
    okno,
    width="10",
    height="5",
    background="orange",
    text="9",
    font=("Arial", 22),
    command=devet,
)

# jedna_tlacitko.config()

devet_tlacitko.grid(row=4, column=3)


osm_tlacitko = Button(
    okno,
    width="10",
    height="5",
    background="orange",
    text="8",
    font=("Arial", 22),
    command=osm,
)

# jedna_tlacitko.config()

osm_tlacitko.grid(row=4, column=2)


plus_tlacitko = Button(
    okno,
    width="10",
    height="5",
    background="orange",
    text="+",
    font=("Arial", 22),
    command=plus,
)

# plus_tlacitko.config()

plus_tlacitko.grid(row=1, column=2)

# plus_tlacitko = Button(okno, width="14", height="6", background="orange")


minus_tlacitko = Button(
    okno,
    width="10",
    height="5",
    background="orange",
    text="-",
    font=("Arial", 22),
    command=minus,
)

# minus_tlacitko.config()

minus_tlacitko.grid(row=1, column=3)


vynulovat_tlacitko = Button(
    okno,
    width="10",
    height="5",
    bg="#ff00c0",
    highlightbackground="#ff00c0",
    background="orange",
    text="vynulovat",
    font=("Arial", 22),
    command=vynulovat,
)

# minus_tlacitko.config()

vynulovat_tlacitko.grid(row=5, column=3)

nadruhou_tlacitko = Button(
    okno,
    width="10",
    height="5",
    bg="#ff00c0",
    highlightbackground="#ff00c0",
    background="orange",
    text="x^2",
    font=("Arial", 22),
    command=nadruhou,
)

# minus_tlacitko.config()

nadruhou_tlacitko.grid(row=1, column=4)


rovnase_tlacitko = Button(
    okno,
    width="10",
    height="5",
    background="orange",
    text="=",
    font=("Arial", 22),
    command=rovnase_funkce,
)

# minus_tlacitko.config()

rovnase_tlacitko.grid(row=5, column=2)


stav = Label(
    okno,
    text=cislo_prvni + znamenko + cislo_druhe + rovnase + vysledek,
    font=("Arial", 36),
)

stav.grid(row=1, column=5)


okno.mainloop()



#config
#vynulovat
# ff00c0

# ,bg='#ff00c0'

# highlightbackground='#3E4149'
