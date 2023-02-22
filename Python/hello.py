def world():
    print('Hello, World!')

nama = "Akhmad Nizar Z"

class Penilai:
    def __init__(self,nama, kelas):
        self.nama = nama
        self.kelas = kelas
    
    def review(self):
        print("Guru: "+ self.nama+" Bertanggung Jawab di Kelas: "+self.kelas)
    