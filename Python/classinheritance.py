class calculator:
    def __init__(self,nilai=0):
        self.nilai = nilai
    
    def add_numbers(self,number1,number2):
        self.nilai = number1+number2

        if self.nilai > 9:
            print("melebihi angka maksimum dari calculator: {}".format(self.nilai))
        return self.nilai

class calculatorKW(calculator):
    def multiple_numbers(self,number1,number2):
        self.nilai = number1 * number2
        return self.nilai
    
    def add_numbers(self, number1, number2):
        return super().add_numbers(number1, number2)

'''
    def add_numbers(self, number1, number2):
        self.nilai = number1+number2
        return self.nilai
'''

class pegawai:
    pass

don = pegawai()

don.nama = "Name DON"
don.bagian = "IT AUTOMATION"
don.salary = "10000$"

Calc = calculator()
CalcKW = calculatorKW()
print(Calc.add_numbers(8,5))
print(CalcKW.multiple_numbers(9,9))
print(CalcKW.add_numbers(10,9))
print(don.nama)