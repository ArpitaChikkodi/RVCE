from tkinter import *
import tkinter.messagebox as tm

window = Tk()
window.title('LoginForm')
window.geometry("400x300")

user = StringVar()
user.set('')

pwd = StringVar()
pwd.set('')

def checklogin():
    if user.get() == 'abc' and pwd.get() == '123':
        tm.showinfo("LoggedIn","Welcome")
    else:
        tm.showerror("Error","Invalid data!")

def checkclear():
    user.set('')
    pwd.set('')
#l1 = Label(window,text = 'Login Form',font = 'Helvetica 15 bold').grid(row=0,column=2)
l2 = Label(window,text = 'Username').grid(row=2,column=2,sticky = 'E',pady=10)
l3 = Label(window,text = 'Password').grid(row=3,column=2,sticky = 'E')

e1 = Entry(window,textvariable=user).grid(row=2,column=3)
e2 = Entry(window,textvariable=pwd,show='*').grid(row=3,column=3)

b1 = Button(window,text='Ok',command=checklogin).grid(row = 4,column = 2,pady=10)
b2 = Button(window,text='Clear',command=checkclear).grid(row = 4,column = 3)

window.mainloop()
