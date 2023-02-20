from cProfile import label
from cgitb import text
from tkinter import *
import tkinter 
from turtle import right
from PIL import ImageTk, Image

global kata_dariuser

tk = Tk()
tk.title("Kamus Sederhana Bergambar")
frame = Frame(tk)
frame.grid(row=1)
tk.geometry("700x500")
my_label = Label()
my_label.grid()

'''
frame = Frame(win, width=600, height=400)
frame.pack()
frame.place(anchor='center', relx=0.5, rely=0.5)

# Create an object of tkinter ImageTk
img = ImageTk.PhotoImage(Image.open("forest.jpg"))

# Create a Label Widget to display the text or Image
label = Label(frame, image = img)
label.pack()

img = ImageTk.PhotoImage(Image.open("idol1.jpg"))
label = Label(frame, image = img)
label.pack()  


'''

  


def translate(kata):
    kamus = {
    "fish": "ikan",
    "car": "mobil",
    "phone": "telepon",
    "computer": "komputer",
    "school": "sekolah",
    "Nizar": "Tidak WIBU",
    "Eko":"WIBU",
    "Fadhil":"WIBU",
    "Gebs":"WIBU",
    "FAqh":"WIBU",
    "Akmal":"WIBU",
    "Dapido":"WIBU"
    }

    
    
    if kata in kamus:
        return(kata+ " artinya adalah: "+ kamus[kata])
    else:
        return("maaf, terjemahan belum ditemukan")

def PrintGANN():
    ans= translate(Entry1.get())
    HasilTerjemah.delete(first=0,last=None)
    HasilTerjemah.insert(1,ans)

def meneng():
    filewin= tkinter.Toplevel(tk)
    button=tkinter.Button(filewin,text="COSPLAY WATU")
    button.pack()

def keluarkan_gambar():
    return Entry1.get()

#fungsi MENU
menubar= tkinter.Menu(tk)
fileMenu=tkinter.Menu(menubar,tearoff=0)
fileMenu.add_command(label="Meneng",command=meneng)
fileMenu.add_command(label="Exit",command=tk.quit)
menubar.add_cascade(label="File",menu=fileMenu)
tk.config(menu=menubar)

#canvas = Canvas(tk, width=300,height=300)
#Fungsi UTAMA
# Create an object of tkinter ImageTk
# Create a Label Widget to display the text or Image

name1=Label(tk,text="Kata")
Entry1 = Entry(tk,bd=5)
button= Button(tk, text='Translate',width=30,command=PrintGANN)
OutPut = Label(frame, text="Hasil Terjemahan: ")
HasilTerjemah = Listbox(frame,height=1,width=35,bd=2)

def myClick():
    link = r'C:/Users/ASUS/Documents/vscode latihan/prakpemlan/bab 10' + Entry1.get()
    my_img = ImageTk.PhotoImage(Image.open(link))
    my_label.configure(image=my_img)
    my_label.image = my_img


myButton = Button(tk, text='Scan Part Number', command=myClick,
                  bg='pink', fg='white')

image = (Image.open(keluarkan_gambar))
resize_image = image.resize((200, 250))
img = ImageTk.PhotoImage(resize_image)
label1 = Label(image=img)
label1.image = img

name1.grid(row = 0, column = 0, sticky = W, pady = 2)
Entry1.grid(row = 0, columnspan = 1, sticky = E, pady = 2)
button.grid(row = 3, column = 0, sticky = W, pady = 2)
OutPut.grid(row=1,sticky=E)
HasilTerjemah.grid(row=1,column=1,sticky=W)
label1.grid(row = 1,column =2)
tk.mainloop()