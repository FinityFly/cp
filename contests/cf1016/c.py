import math

def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    limit = int(math.sqrt(n)) + 1
    for i in range(5, limit, 6):
        if n % i == 0 or n % (i + 2) == 0:
            return False
    return True

def solve(x, k):
    if x % 2 == 0:
        return "NO"
    if k == 1:
        return "YES" if is_prime(x) else "NO"
    if x == 1 and k == 2:
        return "YES"
    return "NO"

t = int(input())
for _ in range(t):
    x, k = map(int, input().split())
    print(solve(x, k))
