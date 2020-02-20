from tkinter import *

window = Tk()
canvas = Canvas(window)
window.geometry("400x400")
x = 0
def movement():
    global x
    x = x + 1
    if(x==16):
        movement2()
    canvas.move("car",2,0)
    canvas.after(100,movement)

def movement2():
    global x
    x = x - 1
    if(x==0):
        movement()
    canvas.move("car",-2,0)
    canvas.after(100,movement2)
    

rec = canvas.create_rectangle(20,120,180,220,tags="car")
l1 = canvas.create_line(20,120,80,80,tags="car")
l2 = canvas.create_line(130,80,180,120,tags="car")
l3 = canvas.create_line(80,80,130,80,tags="car")

o1 = canvas.create_oval(45,220,80,250,tags="car")
o1 = canvas.create_oval(130,220,165,250,tags="car")

l4 = canvas.create_line(180,220,260,220,tags="car")
l5 = canvas.create_line(180,120,260,150,tags="car")
l6 = canvas.create_line(260,150,260,220,tags="car")
canvas.pack()

movement()
window.mainloop()

