k = int(input())
for i in range(k):
    n = int(input())
    n -= 1
    digits = 1
    while True:
        total = 9 * (10 ** (digits - 1)) * digits
        if n < total:
            num = 10 ** (digits - 1) + n // digits
            print(int(str(num)[n % digits]))
            break
        n -= total
        digits += 1