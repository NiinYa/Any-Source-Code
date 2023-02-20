# Import required libraries
from tkinter import *
from PIL import ImageTk, Image

# Create an instance of tkinter window
win = Tk()

# Define the geometry of the window
win.geometry("700x500")

frame = Frame(win, width=600, height=400)
frame.pack()
frame.place(anchor='center', relx=0.5, rely=0.5)

# Create an object of tkinter ImageTk
image = Image.open("idol1.jpeg")
resize_image = image.resize((200, 250))
img = ImageTk.PhotoImage(resize_image)
# Create a Label Widget to display the text or Image

label1 = win.Label(image=img)
label1.image = img
label1.grid(row = 1,column =2)
 
'''label = Label(frame, image = img)
label.pack()'''

win.mainloop()