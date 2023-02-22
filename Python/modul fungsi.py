#membuat fungsi
def namaFungsi (val):
    return val**2

nilaiVal = int(input("masukan nilai input: "))
print(namaFungsi(nilaiVal))

def change(list_ku):
    #jika .append dihapus maka keluaran akan dirubah (bukan ditambah)
    list_ku.append([1,1,2,3,6])
    print('Nilai dalam List: {}'.format(list_ku))

list_ku = [23,43,12]
change(list_ku)
print('Nilai di Luar Fngsi: {}'.format(list_ku))

#penulisan parameter key dan value

def tampilkanInfo(*args, **kwargs):
    for i in args:
        print('argumen posisi: {}'.format(i))
    for key, value in kwargs.items():
        print('argumen kata kunci: {}'.format(key, value))
    print('\n')
tampilkanInfo(2,7)
tampilkanInfo(1,6,X=2,Y=9)
tampilkanInfo(*(8,9),**{'i':9,'b':90})

kali = lambda nilai1, nilai2: nilai1 * nilai2
print ("Hasil : ", kali( 11, 21 ))
print ("Hasil : ", kali( 2, 2 ))