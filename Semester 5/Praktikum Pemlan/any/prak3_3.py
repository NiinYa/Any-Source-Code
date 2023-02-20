'''
Buatlah program yang dapat memastikan bahwa angka yang diinputkan
merupakan bilangan genap.
Input : 1. Bilangan bulat untuk menentukan jumlah angka yang akan dimasukkan
2. n buah bilangan yang akan diperiksa
'''

genap= int(input("Masukan Bilangan Genap: "))

if genap %2 != 0:
    print("Bukan Angka Genap")
elif genap %2 == 0:
    print(genap)
else:
    print("Salah Masukan")