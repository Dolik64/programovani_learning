#time sleep


import tkinter

from tkinter import *
import time

mGui = Tk()
mGui.title('GUI Example')
mGui.geometry('1024x576+10+30')

def zkouska():
    #Canvas
    canvas_1 = Canvas(mGui,height=500,width=500,bg='grey')

    #################
    canvas_1.pack()
    #################

    for i in range(1, 500):
        time.sleep(0.2)
        canvas_1.create_line(0,0,i,i)
        canvas_1.update()

    mGui.mainloop()

zkouska()