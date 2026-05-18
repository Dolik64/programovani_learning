from distutils import command
from tkinter import *
import random
from tkinter import messagebox

pocet = random.randint(3,5)
#if pocet % 4 == 0:
    #pocet = pocet - 1
pocet = 4 * pocet


tri_tahy = 0
okno = Tk()
okno.title('Zápalky')
okno.geometry("700x200")
test = 0


def pravidlo():
    pass

def pryc():
    zapalky[0].destroy()
    global pocet
    global tri_tahy
    pocet = pocet -1
    lbl_popis.config(text="Na stole je "+str(pocet)+" zápalek")
    tri_tahy = tri_tahy + 1

#když se klikne na zápalku
def klik(i):
    global test
    #hlídá se maximum odebraných zápalek
    if True:
            
           # test = 0
            if test < 3:
        #if tri_tahy <= 3:
       # if 4 > 2:
     #  for k in range(3):
                zapalky[i].destroy()
                #global pocet
            # global tri_tahy
                #pocet = pocet -1
                lbl_popis.config(text="Na stole je "+str(pocet)+" zápalek")
                test = test + 1
            #tri_tahy = tri_tahy + 1
        #else:
          #  messagebox.showinfo("Jiz si hral trikrat, ukonci prosim tah", "Jiz si hral trikrat, ukonci prosim tah")
    else:
        pass

#tah počítače
def hraje_pocitac():
    global tri_tahy
    tri_tahy = tri_tahy + 1
    #tri_tahy = 0

    pass

#komponenty v okně:

lbl_popis = Label(okno, text="Na stole je "+str(test)+" zápalek", font=("Arial", 12))
lbl_popis.pack()

btn_konec_tahu = Button(okno, text="Konec tahu", command = hraje_pocitac)
btn_konec_tahu.pack()
   
zapalky=[]
for i in range(pocet):
    #if tri_tahy <= 3:
   # if 4<5:

        btn_zapalka = Button(okno, background="white",
                            width="2", height="6",
                            command=lambda z=i: klik(z) and pravidlo())
        btn_zapalka.pack(side="left")
        zapalky.append(btn_zapalka)
        tri_tahy = tri_tahy + 1
    #else:
 #       messagebox.showinfo("Jiz si hral trikrat, ukonci prosim tah")

okno.mainloop()

#if tri_tahy <= 3: