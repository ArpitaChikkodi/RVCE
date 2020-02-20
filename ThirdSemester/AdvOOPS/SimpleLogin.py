from tkinter import *
import tkinter.messagebox as tm

def loginclicked():
    username = user.get()
    password = pwd.get()
    # print(username, password)
    if user == "arpita" and pwd == "123":
        tm.showinfo("Login info", "Welcome")
    else:
        tm.showerror("Login error", "Incorrect username")
        
window = Tk()
l1 = Label(window,text="Username")
l2 = Label(window,text="Password")

user = Entry(window)
pwd = Entry(window)

l1.grid(row = 0,sticky = E)
l2.grid(row = 1,sticky = E)

user.grid(row = 0,column=1)
pwd.grid(row = 0,column=1)

logbtn = Button(text="Login", command= loginclicked())
logbtn.grid(columnspan=2)

window.mainloop()
