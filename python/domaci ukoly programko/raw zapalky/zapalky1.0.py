from tkinter import *
import random
from tkinter import messagebox

pocet = random.randint(20,30)
pocatek = pocet
limit = 0

okno = Tk()
okno.title('Zápalky')
okno.geometry("700x200")
matches_temp=[]

#když se klikne na zápalku
def klik(i):
  global limit
    #hlídá se maximum odebraných zápalek
  if True:
      #  if pocatek - pocet <= 3:
      if limit < 3:
            zapalky[i].destroy()
            global pocet
            pocet = pocet -1
            lbl_popis.config(text="Na stole je "+str(pocet)+" zápalek")
            limit = limit + 1
      else:
             messagebox.showinfo("Jiz si hral trikrat, ukonci prosim tah", "Jiz si hral trikrat, ukonci prosim tah")
  else:
        pass

def pryc(i):
  global pocet
  if True:
    #zapalky[0].destroy()
  #  pocet = pocet -1
    x = matches_temp[i]
    zapalky[x].destroy()


#tah počítače
def hraje_pocitac():
  global limit
  global pocet
  if True:
    if limit == 0:
      messagebox.showinfo("hraj", "musis alespon jednu zapalku ubrat")
    else:
      limit = 0
      print(pocet)
      if pocet % 4 == 0:
       # zapalky[i].destroy()
       # pocet = pocet -1
        pryc
        lbl_popis.config(text="Na stole je "+str(pocet)+" zápalek")
        print("beru zapalku")
      
      pocet = pocet -1
      #pass

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
  #  test = pocet + 1

#icko = Label(okno, text=str(i))
#icko.pack()

okno.mainloop()


#tohle je posledni verze zapalek
