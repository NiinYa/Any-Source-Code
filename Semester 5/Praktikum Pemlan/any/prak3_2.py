'''
Anda diminta membuat huruf C. Huruf C tersebut akan dibuat di karton berukuran
N*M, dengan ketebalan huruf L. Agar tidak terjadi kesalahan, anda memutuskan
untuk membuat program untuk menggambar hasil akhirnya. Untuk lebih jelasnya,
perhatikan contoh keluaran.
Input : Satu baris berisi 3 buah bilangan bulat N, M, dan L, masing-masing
menyatakan tinggi, lebar karton, dan ketebalan huruf.
Output : N baris, dimana tiap baris berisi M karakter. Gunakan karakter '*' untuk
menandai karton yang dicat, dan '.' untuk karton yang tidak dicat.
'''

N=int(input("masukan Panjang: "))
M=int(input("masukan Tinggi: "))
L=int(input("masukan Tebal: "))

C= int (M/3)

for i in range(C):
    print("*" * N)
A= N-L
B= N-A
for i in range(C):
    print("*" * B,"\'"*A)
    

for i in range(C):
    print("*" * N)
