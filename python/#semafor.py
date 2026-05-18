#semafor

import tkinter

#okno.title("Kalkulacka")

#okno.geometry("1100x800")

canvas = tkinter.Canvas()
#canvas.title("semafor")
#canvas.geometry("600x600")
canvas.pack()



canvas.create_rectangle(50, 30, 190, 510, fill='black')

tkinter.mainloop()