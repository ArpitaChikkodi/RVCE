from tkinter import *
import tkinter.messagebox as tm
window = Tk()
window.title("Login Form")
window.geometry("500x300")
uid = StringVar()
uid.set('')

pid = StringVar()
pid.set('')
def checklogin():
    user = uid.get()
    pwd = pid.get()
    if(user=="abc" and pwd=="123"):
        tm.showinfo("Success","Logged in successfully!")
    else:
        tm.showerror("Error","Invalid details!")

def checkclear():
    uid.set('')
    pid.set('')
l1 = Label(window,text="Login Form",font = 'Helvetica 20 bold').grid(row=1,column=3)
l2 = Label(window,text = "Username").grid(row=3,column=2)
e2 = Entry(window,textvariable=uid).grid(row=3,column=3)
l3 = Label(window,text = "Password").grid(row=4,column=2)
e3 = Entry(window,textvariable=pid,show ='*').grid(row=4,column=3)

b1 = Button(window,text="Login",command = checklogin).grid(row=5,column=2)
b2 = Button(window,text="Clear",command = checkclear).grid(row=5,column=4)

window.mainloop()


