from tkinter import *
window = Tk()
window.geometry("700x350")
val1 = DoubleVar()
val1.set('')

val2 = DoubleVar()
val2.set('')

val3 = DoubleVar()
val3.set('')

val4 = DoubleVar()
val4.set('')

res = DoubleVar()
res.set('')
def GConversion():
    v = (val1.get()*0.35)
    res.set(v)

def KConversion():
    v = (val2.get()*2.204)
    res.set(v)

def AConversion():
    v=(val3.get()*2.205)
    res.set(v)

def CConversion():
    v = (val4.get()*1.8+32)
    res.set(v)

l1 = Label(window,text="Conversion Module").grid(row=1,column=3)
l1 = Label(window,text="Gram value").grid(row=3,column=2,padx = 70,pady=15)
l1 = Label(window,text="Kilo value").grid(row=4,column=2,pady=15)
l1 = Label(window,text="Ahr value").grid(row=5,column=2,pady=15)
l1 = Label(window,text="Celsius value").grid(row=6,column=2,pady=15)

e1 = Entry(window,textvariable = val1).grid(row=3,column=3)
e2 = Entry(window,textvariable = val2).grid(row=4,column=3)
e3 = Entry(window,textvariable = val3).grid(row=5,column=3)
e4 = Entry(window,textvariable = val4).grid(row=6,column=3)

b1 = Button(window,text='Ounce',command = GConversion).grid(row=3,column=4,padx=5)
b1 = Button(window,text='Pounds',command = KConversion).grid(row=4,column=4,padx=5)
b1 = Button(window,text='Stone',command = AConversion).grid(row=5,column=4,padx=5)
b1 = Button(window,text='Fahrenheit',command = CConversion).grid(row=6,column=4,padx=5)

l1 = Label(window,textvariable=res).grid(row=7,column = 2)
window.mainloop()
