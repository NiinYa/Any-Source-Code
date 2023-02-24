print("mau kemana bos!")

x="anjay"
print(x)

y=int(input("masukan umur anda: "))
#print(y,type(y))

if y<17:
    print("belum cukup umur untuk mendapatkan KTP")
else:
    print("sudah cukup umur untuk mendapatkan KTP")
    print("mau sekalian membuat SIM")
    masukan1=input("Y/N")
    if masukan1=="Y":
        print("Anda bisa mengurusnya di kantor polisi")
    else:
        print("Terima Kasih telah mengurus KTP di sini")

anjay= 10

for i in range(anjay):
    print("perulangan ke-",i+1)

item=['anjay','mabar','main','dota']

for isi in item:
    print (isi)


jawab='Y'
hitung=0

while(jawab=='Y'):
    hitung += 1
    jawab=input("Ulang atau tidak?:")

print("Anda telah mengulangi sebanyak: ",hitung-1)

jawab1='Ya'
hitung1= 0

while(True):
    hitung1 += 1
    jawab=input("Ulang lagi atau tidak?")
    if(jawab=='tidak'):
        break

print("total perulangan: ",hitung1-1)



anjay = ["mabar","maba","kembar"]

print (anjay[0])
    