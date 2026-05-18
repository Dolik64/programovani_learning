from tkinter import *
import random
from tkinter import messagebox

pocet = random.randint(20,30)
odber = pocet
limit = 0
vyhra = 0

okno = Tk()
okno.title('Zápalky')
okno.geometry("700x200")

#když se klikne na zápalku
def klik(i):
    global vyhra
    global limit
    #hlídá se maximum odebraných zápalek
    if True:
        if limit < 3:

            zapalky[i].destroy()
            del zapalky[i]
            global pocet
            pocet = pocet -1
            lbl_popis.config(text="Na stole je "+str(pocet)+" zápalek")
            limit = limit + 1
            if len(test) == 0:
                test.append(1)
            if pocet == 0:
                messagebox.showinfo("Yes!!!", "vyhral jsi")
                
                vyhra = 1
        else:
            messagebox.showinfo("Yes!!!", "nech hrat pocitac")



def pryc(i):
    if True:
        zapalky[i].destroy()
        del zapalky[i]
        global pocet
        pocet = pocet -1
        lbl_popis.config(text="Na stole je "+str(pocet)+" zápalek")

#tah počítače
def hraje_pocitac():
    global vyhra
    global odber
    global limit
    if vyhra == 0:

        if len(test) == 0:
            messagebox.showinfo("Yes!!!", "ber zapalku")
        else:
            del test [0]
            limit = 0
            if len(zapalky) % 4 == 0:
                pryc(len (zapalky) - 1)
                if pocet == 0:
                    messagebox.showinfo("Yes!!!", "prohral jsi")
            elif len(zapalky) % 4 == 1:
                pryc(len (zapalky) - 1)
                if pocet == 0:
                    messagebox.showinfo("Yes!!!", "prohral jsi")
            elif len(zapalky) % 4 == 2:
                for l in range(2):
                    pryc(len (zapalky) - 1)
                if pocet == 0:
                    messagebox.showinfo("Yes!!!", "prohral jsi")
            elif len(zapalky) % 4 == 3:
                for k in range(3):
                    pryc(len (zapalky) - 1)
                if pocet == 0:
                    messagebox.showinfo("Yes!!!", "prohral jsi")
            
    #print(len(zapalky))
    

#komponenty v okně:

lbl_popis = Label(okno, text="Na stole je "+str(pocet)+" zápalek", font=("Arial", 12))
lbl_popis.pack()

btn_konec_tahu = Button(okno, text="Konec tahu", command = hraje_pocitac)
btn_konec_tahu.pack()
   
druhy_seznam = []
test=[]
zapalky=[]
for i in range(pocet):
    btn_zapalka = Button(okno, background="white",
                         width="2", height="6",
                         command=lambda z=i: klik(z))
    btn_zapalka.pack(side="left")
    zapalky.append(btn_zapalka)
    druhy_seznam.append(i)

okno.mainloop()
