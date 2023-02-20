from abc import ABC, abstractclassmethod

class AbstractFunc(ABC):
    @abstractclassmethod
    def Add(self,x,y):
        pass
    @abstractclassmethod
    def Subs(self,x,y):
        pass
    @abstractclassmethod
    def multiple(self,x,y):
        pass
    @abstractclassmethod
    def division(self,x,y):
        pass

class Calculator(AbstractFunc):
    def Add(self,x,y):
        add = x + y
        print(add)
    def Subs(self,x,y):
        subs = x - y
        print(subs)
    def multiple(self,x,y):
        mult = x * y
        print(mult) 
    def division(self,x,y):
        try: 
            return x / y
        except ZeroDivisionError:
            print("salah masukan,pembagi tidak boleh angka 0")

main = Calculator()
print("Fungsi Kalkulator\n1.Penjumlahan\n2.Pengurangan\n3.Perkalian\n4.Pembagian\n5.Exit")
sekolah = "masuk"
while sekolah == "masuk":
    pilihan=int(input("Masukan Menu yang anda pilih: "))
    if pilihan == 1:
        x=int(input("Masukan Angka Pertama: "))
        y=int(input("Masukan Angka Kedua: "))
        main.Add(x,y)
    elif pilihan == 2:
        x=int(input("Masukan Angka Pertama: "))
        y=int(input("Masukan Angka Kedua: "))
        main.Subs(x,y)
    elif pilihan == 3:
        x=int(input("Masukan Angka Pertama: "))
        y=int(input("Masukan Angka Kedua: "))
        main.multiple(x,y)
    elif pilihan == 4:
        x=int(input("Masukan Angka Pertama: "))
        y=int(input("Masukan Angka Kedua: "))
        print(main.division(x,y))
    elif pilihan == 5:
        sekolah = "libur"