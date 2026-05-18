from tkinter import *
import random
from tkinter import messagebox

pocet = random.randint(20,30)

okno = Tk()
okno.title('Zápalky')
okno.geometry("700x200")
odber = pocet


seznam_pro_jirku=[]
for k in range (odber):
    x = 0
    str(x)
    seznam_pro_jirku.append(x)
   # int(x)
  #  x = x + 1


#když se klikne na zápalku
def klik(i):
    #hlídá se maximum odebraných zápalek
    if True:
        zapalky[i].destroy()
        seznam_pro_jirku.destroy()
        #zapalky[0].destroy()
      #  zapalky.pop[i]
        zapalky[0].pop()
        global pocet
        pocet = pocet -1
        lbl_popis.config(text="Na stole je "+str(pocet)+" zápalek")
    else:
        pass

#tah počítače
def hraje_pocitac():
   # global odber
    print(len(seznam_pro_jirku))
    print(len(zapalky))


#komponenty v okně:

lbl_popis = Label(okno, text="Na stole je "+str(pocet)+" zápalek", font=("Arial", 12))
lbl_popis.pack()

btn_konec_tahu = Button(okno, text="Konec tahu", command = hraje_pocitac)
btn_konec_tahu.pack()
   
zapalky=[]
for i in range(pocet):
    btn_zapalka = Button(okno, background="white",
                         width="2", height="6",
                         command=lambda z=i: klik(z))
    btn_zapalka.pack(side="left")
    zapalky.append(btn_zapalka)


okno.mainloop()
