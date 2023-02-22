class namaKelas:
    pass

class calculator:
    def __init__(self,i=12345):
        self.i = i

    def f(self):
        return "Hello,World!"

    def tambah_angka(cls,angka1,angka2):
        return '{} + {} = {}'.format(angka1,angka2,angka1+angka2)
    
    def kali_angka(cls,angka1,angka2):
        return '{} x {} = {}'.format(angka1,angka2,angka1*angka2)
calculator(i = 1024)
calc = calculator()
print(calc.i)
print(calc.f())
print(calc.tambah_angka(7,10))
print(calc.kali_angka(9,87))