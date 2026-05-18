from tkinter import *
import random
from tkinter import messagebox
matches_count=random.randint(10,30)
removed = 0

okno = Tk()
okno.title('Hra se zápalkami')
okno.geometry("500x500")
matches=[]
matches_temp=[]
matches_round=0

lbl_text=Label(okno, text="Ve hře je "+str(matches_count)+" zápalek.")
lbl_text.pack(side="top")

lbl_text1=Label(okno, text="Počítač odebral 0 zápalek.")
lbl_text1.pack(side="top")

kontejner=LabelFrame()
kontejner.pack(side="top",pady=20)

def remove(i):
    global removed

    if(removed<3):
        matches[i].destroy()
        matches_temp.remove(i)
        lbl_text.config(text="Ve hře je "+str(len(matches_temp))+" zápalek.")
        removed+=1
    else:
        messagebox.showinfo("Varování","Můžeš tahat jen 3 zápalky za kolo.")
    
    if len(matches_temp)==0:
        messagebox.showinfo("Konec hry","Vyhrál jsi :)!")

    
    
def end_turn(i):
    global removed
    removed=0

    if len(matches_temp)%4 == 3:
        for i in range(3):
            x = matches_temp[i]
            matches[x].destroy()
            matches_temp.remove(x)
            lbl_text1.config(text="Počítač odebral "+str(3)+" zápalky.")
    elif len(matches_temp)%4 == 2:
        for i in range(2):
            x = matches_temp[i]
            matches[x].destroy()
            matches_temp.remove(x)
            lbl_text1.config(text="Počítač odebral "+str(2)+" zápalky.")
    elif len(matches_temp)%4 == 1:
        for i in range(1):
            x = matches_temp[i]
            matches[x].destroy()
            matches_temp.remove(x)
            lbl_text1.config(text="Počítač odebral "+str(1)+" zápalku.")
    else: 
        z=random.randint(1,3)
        for i in range(z):
            x = matches_temp[i]
            matches[x].destroy()
            matches_temp.remove(x)
            if z>1:
                lbl_text1.config(text="Počítač odebral "+str(z)+" zápalky.")
            else:
                lbl_text1.config(text="Počítač odebral "+str(z)+" zápalku.")
    
    if len(matches_temp)==0:
        messagebox.showinfo("Konec hry","Vyhrál počítač.")

    lbl_text.config(text="Ve hře je "+str(len(matches_temp))+" zápalek.")

    
    

for i in range(matches_count):
    match=Button(kontejner, width="2", height="5", background="orange", command=lambda z=i:remove(z))
    match.pack(side="left", padx=2)
    matches_temp.append(i)
    matches.append(match)

endturn=Button(okno, text="Konec tahu", command=lambda z=i:end_turn(z))
endturn.pack(side="top")


okno.mainloop()
