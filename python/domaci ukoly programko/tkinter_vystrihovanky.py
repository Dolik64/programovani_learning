# TkInter

# import knihovny
from tkinter import *

# základní smyčka
okno = Tk()
okno.mainloop()

# titulek okna
okno.title('Moje okno')

# velikost okna
okno.geometry("400x200")

# ukončení okna
okno.destroy

# vykreslení udělátka
.pack()
.grid(row=0, column=0)

# tlačítko
Button(okno, text="OK", command=nazev_funkce)
Button(okno, width="14", height="6", background="orange")

# nápis
Label(okno, text="Ahoj", font=("Comic Sans MS", 16))

#textové pole
Entry(okno, width = 20, bg="blue", fg="red", font=("Arial", 26), justify=CENTER)
e.get()
e.delete(0,"end")
e.insert(0, text)

# plátno
c = Canvas(okno, width=500, height=500)

c.create_line(200, 100, 200, 400, width=5)
c.create_rectangle(x, y, x+sizex, y+sizey, fill="blue")

c.move(co, o_kolik_x, o_kolik_y)

# předání parametrů funkci tlačítka
command= lambda x1=x, y1=y: zmen(x1,y1)

# nastavení barvy tlačítka b
b.config(background="red")

# zjištění barvy tlačítka b
b.cget("background")

# počítání kliknutí
v = IntVar()
v.set(0)
Label(okno, textvariable = v)
v.get()

# messagebox
from tkinter import messagebox
messagebox.showinfo("Yes!!!", "Hurá")

# stisky kláves
def funkce(udalost):
    print(udalost.char)

okno.bind("<Key>", funkce)

# tutorial
http://tkinter.py.cz/

# reference
https://tkdocs.com/shipman/index.html

#a další...
https://www.root.cz/clanky/graficke-uzivatelske-rozhrani-v-pythonu-knihovna-tkinter/
