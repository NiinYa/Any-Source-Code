#nama: Akhmad Nizar Zakaria
#NIM: 205150300111040
'''
materi meliputi
1. dict
2. konversi string
3. slicing
4. indexing
5. operator spesial'''

#pencatatan penjualan produk

harga_BP={
    'nama': "battlepass",
    'harga': 100000,
}
harga_Skin={
    'nama': "skin",
    'harga': 15000,
}
harga_Bundle={
    'nama': "Bundle",
    'harga': 200000,
}
totalBelanja=0
jumlah=int(input("Perkiraan Barang yang akan anda beli: "))
print("Pilihan Produk antara lain: \n1.battlepass\n2.skin\n3.Bundle")
masukan1=[]
i=0
for i in range(jumlah):
    masukan=input("Masukan nama barang yang akan anda beli: ")
    masukan1.append(masukan)
    if masukan == harga_BP.get('nama'):
        totalBelanja+= harga_BP.get('harga')
    elif masukan == harga_Bundle.get('nama'):
        totalBelanja+= harga_Bundle.get('harga')
    elif masukan == harga_Skin.get('nama'):
        totalBelanja+= harga_Skin.get('harga')
    else:
        print("Masukan yang anda masukan salah")
    i+=1

print("Barang yang anda beli: ",masukan1,"Total yang perlu dibayar: ",totalBelanja)
