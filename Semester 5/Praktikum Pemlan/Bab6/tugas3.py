'''
Nama: Akhmad Nizar Zakaria
NIM: 205150300111040
membuat program bebas
menerapkan 2 dari 3 materi bab 6
'''
from datetime import datetime


kumpulanMember={'Nama': 'Akhmad Nizar Z',
'Tanggal Join':'Sejak AWAL',
'Member ke': 1}
punyapacar = "ya"
tanggal = datetime.now()
tanggalFix = tanggal.strftime("%B %d, %Y %H:%M")
print("1. Daftar Member\n2.Lihat Daftar Member\n3.Keluar")
while punyapacar=="ya":
    pilihan=str(input("Masukan Pilian Menu Anda: "))
    if pilihan == "1":
        memberBaru = input("Masukan Nama Anda: ")

        with open("Data Member.txt", 'r') as fp:
            for count, line in enumerate(fp):
                pass
        gabungan = [memberBaru,tanggalFix,count+2]
        listkeStr = ' '.join([str(elem) for elem in gabungan])
        print(listkeStr)

        file = open("Data Member.txt", "a")
        file.write("\n"+listkeStr)
        file.close()

        kumpulanMember.update({'Nama':memberBaru,'Tanggal Join':tanggalFix,'Member ke':count+2})
        print("Dictionary after updation:")
        print(kumpulanMember)
    elif pilihan == "2":
        

        f = open("Data Member.txt", "r")
        print(f.read())
        f.close()
    elif pilihan == "3":
        punyapacar="tidak"
    else:
        "salah masukan"
