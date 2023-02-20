def faktorial(n):
    if n == 1:
        return 1
    else:
        return (n * faktorial(n-1))
bil = 5
print("Faktorial dari", bil, " adalah ", faktorial(bil))
