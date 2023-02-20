class coba():
    def bagi(self,x,y):
        try:
            return x / y
        except ZeroDivisionError:
            print("Salah Masukan, Pembilang dan Penyebut tidak boleh angka 0")

ini = coba()

print(ini.bagi(9,0))