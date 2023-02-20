from tkinter import *
from tkinter.filedialog import askopenfilename
from PIL import Image, ImageTk
import tkinter

tk = Tk()

button_quit = Button(tk, text='Exit Program', command=tk.quit)
button_quit.pack()

my_label = Label()
my_label.pack()

def myClick():
    link = askopenfilename()
    my_img = ImageTk.PhotoImage(Image.open(link))
    my_label.configure(image=my_img)
    my_label.image = my_img

def meneng():
    filewin= tkinter.Toplevel(tk)
    button=tkinter.Button(filewin,text="COSPLAY WATU",command=tk.quit,bg='pink', fg='white')
    image = Image.open("watu.png")
    resize_image = image.resize((250, 250))
    img = ImageTk.PhotoImage(resize_image)
# Create a Label Widget to display the text or Image
    my_label.configure(image=img)
    my_label.image = img
    button.pack()

    

#fungsi MENU
menubar= tkinter.Menu(tk)
fileMenu=tkinter.Menu(menubar,tearoff=0)
fileMenu.add_command(label="Meneng",command=meneng)
fileMenu.add_command(label="Exit",command=tk.quit)
menubar.add_cascade(label="File",menu=fileMenu)
tk.config(menu=menubar)

myButton = Button(tk, text='Scan Part Number', command=myClick,
                  bg='pink', fg='white')
myButton.pack()

tk.mainloop()