teman = ["aku","my","watashi","ore","saya"]

nomor=int(input("masukan nomor temanmu: "))
print("nama teman ke-",nomor,"adalah ",teman[nomor])

for nama in teman:
    print (nama)

print ("====================")

hewan = ["anjing","kucing","monyet","cicak","tokek"]

hewan[2] = "tenyom"

for namahewan in hewan:
    print (namahewan)

'''
cara menambahkan data dalam list
1. prepend(item) menambah item dari depan
2. append(item) dari belakang
3. insert(index,item) memasukan di index yang dituju
'''


print("==========================")
hewan = ["anjing","kucing","monyet","cicak","tokek"]

hewan.append("neko")
hewan.insert(4,"poi")

for namahewan1 in hewan:
    print (namahewan1)

hobi= []
stop = False
x= 1

while(not stop):
    hobi = str(input("masukan hobi kamu yang ke-{} ".format(x)))
    x += 1
    tanya = input("apakah ada hobi lainnya ? (y/t)")
    if (tanya == "t"):
        stop = True

print ("="*10)
print  ("kamu memiliki hobi sebanyak {}".format(x-1))

for hobimu in hobi:
    print (hobimu)


print ("="*10)

#del untuk menghapus sebuah node di dalam list


hewan = ["anjing","kucing","monyet","cicak","tokek"]

del hewan[1]

for namahewanlist in hewan:
    print (namahewanlist)


#bisa juga menggunakan remove
print ("="*10)

hewan = ["anjing","kucing","monyet","cicak","tokek"]
hewan.remove("anjing")

for namahewanlist1 in hewan:
    print (namahewanlist1)

print ("="*10)

hewan = ["anjing","kucing","monyet","cicak","tokek"]
print (hewan[1:3])

makanan1= ["rawon","soto","bakso"]

makanan2= ["empal","sushi","udang"]

semua_makanan= makanan2+makanan1

print (semua_makanan)
perulangan = 2
semua_makanan2= semua_makanan*perulangan

print(semua_makanan2)

print ("="*10)
multilevellist=[
    [1,2,3],
    [4,5,6],
    [7,8,9]
]
print ("="*10)

print (multilevellist[1][2])

print ("="*10)
for angkaanjay in multilevellist:
    for angka1 in angkaanjay:
        print(angka1)






