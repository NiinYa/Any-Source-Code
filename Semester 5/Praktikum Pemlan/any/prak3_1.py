'''
Buatlah program yang dapat membedakan tahun kabisat atau bukan tahun kabisat
dengan ketentuan :
- Jika habis dibagi 4 merupakan tahun kabisat.
- Jika habis dibagi 100 bukan merupakan tahun kabisat.
- Jika habis dibagi 400 merupakan tahun kabisat.
Input : satu variabel Integer.
Output : Tahun Kabisat atau Bukan Tahun Kabisat.
Contoh :
- 2040 Tahun Kabisat
- 2100 Bukan Tahun Kabisat
- 2400 Tahun Kabisat
'''

tahun= int(input("masukan Tahun: "))
print(tahun)
if tahun %4 == 0 and tahun %100 != 0:
    print("Tahun Kabisat")
elif tahun %400 == 0:
    print("Tahun Kabisat")
else:
    print("Bukan Tahun Kabisat")


