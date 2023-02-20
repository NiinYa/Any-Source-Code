def check(original, edited):
    if original == edited:
        print("Palindrome")
    else:
        print("Not Palindrome")
def reversed(word):
    return word[::-1]
n = int(input("Jumlah huruf yang ingin diperiksa : "))
for i in range(n):
    kata = input("Tuliskan sebuah kata : ")
    kebalik = reversed(kata)
    check(kata,kebalik)
