#materi kelas terbuka ke 5
#materi tipe data
#a=10 , maka a adalah variabel dan 10 adalah value

data_integer= 10
print("nilai data=",data_integer,("bertipe="),type(data_integer))
#gunakan (type(nama variabel)) untuk mengecek type data apa yang ada di dalamnya

data_float= 10.006753
print("tipe data",type(data_float))
print("bernilai: ",data_float)

data_sting="kmemeemw"
print("tipe data: ",type(data_sting))
print("berisi: ",data_sting)

data_bool1=True
data_bool2=False
print("nilai bool1",data_bool1)
print("tipe data: ",type(data_bool1))
print("nilai bool2",data_bool2)
print("tipe data: ",type(data_bool2))

#type data khusus
#bilangan kompleks
data_complex=complex(3,7)
print("nilai data complex",data_complex)
print("tipe data: ",type(data_complex))

#cara import tipe data dari bahasa c

from ctypes import c_double
data_c_double=c_double(10.650213123123123)
print("nilai data",data_c_double)
print("tipe data: ",type(data_c_double))



print(5//2)