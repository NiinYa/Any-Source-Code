from tkinter import *
from PIL import Image, ImageTk

# How to properly set up Tkinter label with dynamically changeable
# ImageTk.PhotoImage: https://stackoverflow.com/a/3482156/11089932

root = Tk()
root.geometry("700x500")
frame = Frame(root, width=600, height=400)
frame.pack()
frame.place(anchor='center', relx=0.5, rely=0.5)
button_quit = Button(root, text='Exit Program', command=root.quit)
button_quit.pack()

e = Entry(root, width=50, bg='light blue', borderwidth=3)
e.pack()
e.insert(0, '')

my_label = Label()
my_label.pack()


def myClick():
    link = r'C:/Users/ASUS/Documents/vscode latihan/prakpemlan/bab 10/' + e.get()+".jpeg"
    my_img = ImageTk.PhotoImage(Image.open(link))
    my_label.configure(image=my_img)
    my_label.image = my_img

myButton = Button(root, text='Scan Part Number', command=myClick,
                  bg='pink', fg='white')
myButton.pack()

root.mainloop()
