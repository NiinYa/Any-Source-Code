print('perfect world')

#membuat list dan tuple
contohlist= ['nama','ku','nizar'] #bisa dirubah
contohtuple = ('nama','ku','nizar') #tidak bisa dirubah

#membuat dictionary 
#dictionary umur

umur={'mita':22,'fajar':19,'kartika':20,'theo':21,'aku':20}

print(umur['mita'])

angka= float(input('Masukan Angka: '))

if angka>0:
    print('bilangan positif')
elif angka==0:
    print('angka nol')
else:
    print('bilangan negatif')

'''x=1
n=input('Masukkan nilai n : ')
jumlah =0

while (x<=n):
    jumlah += x
    x += 1
print("Jumlah "+str(n)+" bilangan pertama adalah "+str(jumlah))
'''

angka= [1,2,3,4,5,6]

for x in angka:
    print (x)

for index in range(len(angka)):
    print (angka[index])

#membuat list comprehension
nomor= [1,2,3,4,32,12,213]
angkaeksponen= [x*x for x in nomor]

print (angkaeksponen)


berkas=open('D:\Download\jok hapus\Utilitas bangunan lanjut\latihanopenberkas.txt', 'r')
isiberkas=berkas.read()
print(isiberkas)
berkas.close()