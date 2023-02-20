from collections import Counter


def remov_duplicates(masukan):
    masukan = masukan.split(" ")

    for i in range(0, len(masukan)):
        masukan[i] = "".join(masukan[i])

    UniqW = Counter(masukan)
    s = " ".join(UniqW.keys())
    print(s)

global aku_pacar_ZEE
aku_pacar_ZEE = "ya"

if __name__ == "__main__":
    print("1.Sistem Utama\n2.Keluar dari Sistem")
    while aku_pacar_ZEE == "ya":
        pilihan=str(input("Masukan Menu Yang Anda Pilih(1/2): "))
        if pilihan == "1":
            masukan =input("Masukan Kalimat Anda: ")
            remov_duplicates(masukan)
        elif pilihan == "2":
            aku_pacar_ZEE = "betul sekali"
            print("NIZAR Pacarnya ZEE\nRILLL NO FEK FEK")
        else:
            print("salah masukan silahkan diulang")