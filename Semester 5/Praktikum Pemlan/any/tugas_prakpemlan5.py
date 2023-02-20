'''
Nama: Akhmad Nizar Zakaria
NIM: 205150300111040
tugas PrakPemlan Bab 5
membuat sistem login dengan admin dan guest
'''

import csv

with open('datauser.csv','w',newline='') as file:
    tulisae = csv.DictWriter(file,fieldnames= ['Username','Password','HakAkses'])
    tulisae.writeheader()

with open('Dashboard.txt','w',newline='') as file:
    file.write("______Selamat Datang BANG JAGO______")
print("1. LOGIN BANG")
print("2. REGISTER BANG")
print("3. KELUAR BANG")
pacar = 1
while pacar == 1:
    pilihan=int(input("Masukan Pilihan Menu(1/2/3): "))
    if pilihan== 1:
        print("Memasuki Halaman LOGIN BANG")
        with open ('datauser.csv','r') as file:
            pembaca = csv.DictReader(file)
            Namaewa = input("Masukan Username Anda: ")
            Passwordto = input("Masukan Password Anda: ")
            cekk = False
            for row in pembaca:
                if Namaewa == row['Username'] and Passwordto == row['Password']:
                    cekk = True
                if row ['HakAkses'] =='1':
                    ndadi = input("Apa anda ingin mengubah Teks Sambutan(ya/tidak)?: ")
                    if ndadi == 'ya':
                        EditText = input("Masukan Text Pengganti: ")
                        with open('Dashboard.txt','w',newline='') as file:                                
                            file.write(EditText)
                        break
                elif row['HakAkses'] == 0:
                    break
            if cekk == True:
                with open('Dashboard.txt','r') as file:
                    print(file.read())
    elif pilihan == 2:
        print("Anda Memasuki Halaman REGISTER BANG")
        Namaewa = input("Masukan Username Anda: ")
        Passwordto = input("Masukan Password Anda: ")
        authority = input("Masukkan Hak Akses Anda: ")
        if authority == "iamgod":
            authority = '1'
        else:
            authority = '0'
        with open('datauser.csv','a',newline='') as file:
            fieldnames=  ['Username','Password','HakAkses']
            tulisae = csv.DictWriter(file,fieldnames=fieldnames)
            tulisae.writerow({'Username':Namaewa,
            'Password':Passwordto,
            'HakAkses':authority})
    elif pilihan == 3:
        print("Anda Telah Keluar Program\nTerimaKasih")
        pacar = 0
    else:
        print("Salah Memilih Pilihan\nMohon memasukan Pilihan dengan benar")
