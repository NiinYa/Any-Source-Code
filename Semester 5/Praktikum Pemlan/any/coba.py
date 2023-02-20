# -*- coding: utf-8 -*-
"""
Created on Sun Oct 9 21:58:45 2022
@author: Eko P.A
"""
import csv
with open('users.csv', 'w', newline='') as file:
    writer = csv.DictWriter(file,fieldnames=['User','Pass','Aces'])
    writer.writeheader()
with open('hello.txt','w',newline='') as file:
    file.write("WELCOME TO THE SISTEM")
print("1. LOGIN")
print("2. REGISTER")
print("3. EXIT")
while True:
    x = int(input("Masukkan Pilihan : "))
    if x == 1:
        print("HALAMAN LOGIN")
        with open('users.csv', 'r') as file:
            reader = csv.DictReader(file)
            jeneng = (input("Masukkan Username : "))
            pesword = (input("Masukkan Password : "))
            check = False
        for row in reader:
            if jeneng == row['User'] and pesword == row['Pass']:
                check = True
            if row['Aces'] == '1':
                print()
                henshin = (input("Apakah anda inginmerubah welcome text?[ya/tidak]"))
                if henshin == 'ya':
                    ubah = (input("Masukkan Text :"))
                with open('hello.txt','w',newline='') as file:
                    file.write(ubah)
                break
            if check == True:
                with open('hello.txt', 'r') as file:
                    print(file.read())
    elif x == 2:
        print("HALAMAN REGISTER")
        jeneng = (input("Masukkan Username : "))
        pesword = (input("Masukkan Password : "))
        acc = (input("Masukkan Akses : "))
        if acc == 'iamgod':
            acc = '1'
        else:
            acc = '0'
        with open('users.csv', mode='a', newline='') as file:
            fieldnames = ['User', 'Pass', 'Aces']
            writer = csv.DictWriter(file,fieldnames=fieldnames)
            writer.writerow({'User':jeneng, 'Pass':pesword,'Aces':acc})
    elif x ==3:
        print("Keluar Program")
        break
    else:
        print("Error Pilihan Tidak Ada")
