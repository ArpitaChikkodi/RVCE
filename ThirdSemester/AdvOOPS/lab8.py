import tkinter as tk
import time
root = tk.Tk()
w,h = 600,400


canvas = tk.Canvas(root,width=w,height=h)
ball = canvas.create_oval(0,0,80,80,fill='blue')
xspeed = 5
yspeed = 0
canvas.pack()

while True:
    canvas.move(ball,xspeed,yspeed)
    pos = canvas.coords(ball)
    if pos[2]>=w:
        xspeed = -xspeed
    time.sleep(0.1)
    root.update()
root.mainloop()

