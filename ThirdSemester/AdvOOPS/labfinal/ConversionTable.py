from tkinter import *
top = Tk()
top.geometry("300x300")
val1 = DoubleVar()
val1.set('')

val2 = DoubleVar()
val2.set('')

val3 = DoubleVar()
val3.set('')

val4 = DoubleVar()
val4.set('')

val5 = DoubleVar()
val5.set('0')

def GConversion():
    val5.set(round(val1.get()*0.03527,3))

def KConversion():
    val5.set(round(val2.get()*2.204,3))

def AConversion():
    val5.set(round(val3.get()*2.204,3))

def CConversion():
    val5.set(round((val4.get()*1.8)+32,3))

l1 = Label(top,text='Gram').grid(row=1,column=2,pady=10)
l1 = Label(top,text='Kilo').grid(row=2,column=2,pady=10)
l1 = Label(top,text='Ahr').grid(row=3,column=2,pady=10)
l1 = Label(top,text='Celsius').grid(row=4,column=2,pady=10)

e1 = Entry(top,textvariable=val1).grid(row=1,column=3)
e1 = Entry(top,textvariable=val2).grid(row=2,column=3)
e1 = Entry(top,textvariable=val3).grid(row=3,column=3)
e1 = Entry(top,textvariable=val4).grid(row=4,column=3)

b1 = Button(top,text='Ounce',command=GConversion).grid(row=1,column=4,pady=10)
b1 = Button(top,text='Pounds',command=KConversion).grid(row=2,column=4)
b1 = Button(top,text='Stonne',command=AConversion).grid(row=3,column=4)
b1 = Button(top,text='Fahrenheit',command=CConversion).grid(row=4,column=4)

l1 =Label(top,text='Result').grid(row=5,column=3,pady=10)
l1 = Label(top,textvariable=val5).grid(row=5,column=4)

top.mainloop()
