z = 0
try:
    x = 1/z
    print(x)

except ZeroDivisionError:
    print("Tidak bisa dibagi 0")

try:
    with open('anjayMabar.py') as file:
        print(file.read())
except(FileNotFoundError):
    print("FIle tidak ditemukan")

d = {"ratabangg": "10.0"}
try:
    print("rata-rata: {}".format(d['rata_rata']))
except KeyError:
    print("kunci tidak ditemukan di dictionary")
except ValueError:
    print("nilai tidak sesuai")


try:
    print('rata-rata: {}'.format(d['ratarata']/3))
except KeyError:
    print('Kunci tidak ditemukan di dictionary')
except (ValueError,TypeError):
    print('nilai atau tipe tidak sesuai')

try:
    print("pembulatan rata-rata: {}".format(int(d['ratarata'])))
except (ValueError, TypeError) as e:
    print('penanganan kesalahan: {}'.format(e))

d = {'ratarata': '10.0'}
if 'total' not in d:
    raise KeyError('harus memiliki total')
'''
Traceback (most recent call last):
    File "<stdin>", line 2, in <module>
KeyError: 'harus memiliki total'
'''
