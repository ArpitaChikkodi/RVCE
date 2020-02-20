from tkinter import *
top = Tk()
top.title('Moving Car')
top.geometry("500x400")
x = 0
def movement():
    global x
    x = x + 1
    if(x==100):
        return 0
    canvas.move('car',2,0)
    canvas.after(100,movement)

canvas = Canvas(top,width=500,height=300)

r1 = canvas.create_rectangle(20,60,140,140,tags="car")

l1 = canvas.create_line(20,60,55,35,tags='car')
l1 = canvas.create_line(55,35,105,35,tags='car')
l1 = canvas.create_line(105,35,140,60,tags='car')

c1 = canvas.create_oval(40,140,65,165,tags='car')
c1 = canvas.create_oval(120,140,145,165,tags='car')

l1 = canvas.create_line(140,60,205,90,tags='car')
l1 = canvas.create_line(205,90,205,140,tags='car')
l1 = canvas.create_line(140,140,205,140,tags='car')

c1 = canvas.create_oval(130,45,145,55,tags='car')

canvas.place(x=10,y=10)
movement()


top.mainloop()




def movem():
    '''global x
    x = x - 1
    if(x==0):
        return 0'''
    canvas.move('car',-2,0)
    canvas.after(100,movem)

#movem()
