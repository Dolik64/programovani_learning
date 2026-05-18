from tkinter import *

okno = Tk()
okno.title("zapalky")
okno.geometry("1000x400")  

def cudlik():
    if True:
        cudlik_tlacitko.destroy()
        pass


for i in range(3):
    cudlik_tlacitko = Button(okno,background ="red",width=3, height=10, command = cudlik)
    cudlik_tlacitko.grid(row = 0, column = 9*i)

okno.mainloop()