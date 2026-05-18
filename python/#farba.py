#farba

import tkinter
import random

canvas = tkinter.Canvas()
canvas.pack()

for y in range(5, 230, 30):
    for x in range(5, 350, 30):
        r = random.randrange(256)
        g = random.randrange(256)
        b = random.randrange(256)
        farba = f'#{r:02x}{g:02x}{b:02x}'
        print(farba)
        canvas.create_rectangle(x, y, x + 25, y + 25, fill=farba)

tkinter.mainloop()