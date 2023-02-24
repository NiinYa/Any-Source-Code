umur=int(input("Berapa umur kamu: "))

print(type(umur))
if umur > 18:
    print("Kamu boleh membuat SIM")
else:
    print("Kamu belum boleh membuat SIM")

nilai = int(input("Inputkan nilaimu: "))

if nilai >= 90:
   grade = "A"
elif nilai >= 80:
   grade = "B+"
elif nilai >= 70:
   grade = "B"
elif nilai >= 60:
   grade = "C+"
elif nilai >= 50:
   grade = "C"
elif nilai >= 40:
   grade = "D"
else:
   grade = "E"

print("Grade: ",grade)

class Pagar:
    """kelas pagar untuk membuat objek pagar. Dibuat oleh Petani Kode sebagai contoh saja."""
    def __init__(self, warna, tinggi, bahan):
        self.warna = warna
        self.tinggi = tinggi
        self.bahan = bahan

# Mengakses dokumentasi kelas
print(Pagar.__doc__)
input('\ntekan [enter] untuk melihat bantuan (dokumentasi) kelas: ')
help(Pagar) # untuk melihat dokumentasi kelas