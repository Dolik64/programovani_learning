# semafor 2.0

import tkinter as tk

import time

#hnusna oranzova   #2d2101
#hnusna zelena    #032d01
#oranzova      #e08900

def semafor1():
    global podklad
    global cervena
    global oranzova
    global zelena
    window = tk.Tk()
    window.title("semafor")
    window.geometry("960x540+450+250")
    canvas = tk.Canvas(window, width=960, height=540, bd=10, bg='#494949')
    while 0==0:

        podklad = canvas.create_rectangle(340, 30, 620, 510, fill='black')
        cervena = canvas.create_oval     (430, 60, 530, 160, fill='red')
        oranzova = canvas.create_oval     (430, 210, 530, 310, fill='#2d2101')
        zelena = canvas.create_oval     (430, 360, 530, 460, fill='#032d01')
        
        canvas.pack()


        window.mainloop()


        
        #canvas.itemconfig(oranzova, fill="#e08900")
        

semafor1()

"""def semafor2():
    
    window = tk.Tk()
    window.title("semafor")
    window.geometry("960x540+450+250")
    canvas = tk.Canvas(window, width=960, height=540, bd=10, bg='#494949')
    canvas.create_rectangle(340, 30, 620, 510, fill='black')
    canvas.create_oval     (430, 60, 530, 160, fill='red')
    canvas.create_oval     (430, 210, 530, 310, fill='#e08900')
    canvas.create_oval     (430, 360, 530, 460, fill='#032d01')
    canvas.pack()
    window.mainloop()


while 0 == 0:
    semafor1()
    time.sleep(1)
    semafor2()


"""