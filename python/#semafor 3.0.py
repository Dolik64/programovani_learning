#semafor 3.0

import tkinter as tk

import time

#hnusna oranzova   #2d2101
#hnusna zelena    #032d01
#oranzova      #e08900
#hnusna cervena    #450000
#zelena        #00cd0e




#nepozivat loop dokud neuzavru pack
#nepozivat time sleep

"""
global podklad
global cervena
global oranzova
global zelena
"""
okno = tk.Tk()
okno.title("semafor")
okno.geometry("960x540+450+250")
canvas = tk.Canvas(okno, width=960, height=540, bd=10, bg='#494949')

canvas.pack()


def priprav_se_ze_padne_cervena():
    canvas.itemconfig(oranzova, fill="#e08900")  
    canvas.itemconfig(zelena, fill="#032d01")
    canvas.itemconfig(cervena, fill="#450000")
    okno.after(3000, zastav)

def zastav():
    canvas.itemconfig(oranzova, fill="#2d2101")  
    canvas.itemconfig(zelena, fill="#032d01")
    canvas.itemconfig(cervena, fill="red")
    okno.after(5000, priprav_se_pojedes)

def priprav_se_pojedes():
    canvas.itemconfig(oranzova, fill="#e08900")  
    canvas.itemconfig(zelena, fill="#032d01")
    canvas.itemconfig(cervena, fill="red")
    okno.after(1000, jedu)

def jedu():
    canvas.itemconfig(oranzova, fill="#2d2101")  
    canvas.itemconfig(zelena, fill="#00cd0e")
    canvas.itemconfig(cervena, fill="#450000")
    okno.after(5000, priprav_se_ze_padne_cervena)
"""
podklad = canvas.create_rectangle(340, 30, 620, 510, fill='black')
cervena = canvas.create_oval     (430, 60, 530, 160, fill='red')
oranzova = canvas.create_oval     (430, 210, 530, 310, fill='#2d2101')
zelena = canvas.create_oval     (430, 360, 530, 460, fill='#032d01')
        
canvas.pack()
"""

podklad = canvas.create_rectangle(340, 30, 620, 510, fill='black')
cervena = canvas.create_oval     (430, 60, 530, 160, fill='#450000')
oranzova = canvas.create_oval     (430, 210, 530, 310, fill='#2d2101')
zelena = canvas.create_oval     (430, 360, 530, 460, fill='#00cd0e')

okno.after(5000, priprav_se_ze_padne_cervena)

okno.mainloop()


"""  
time.sleep(5)
canvas.itemconfig(oranzova, fill="#e08900")  
"""