def main():
    n = int(input())
    test_case_execution(n)

def sum_squares(x, y):
    if x == 0:
        return 0
    else:

        if int(y[x-1]) < 0:
            return sum_squares(x-1, y)
        else:
            return pow(int(y[x-1]), 2) + sum_squares(x-1, y)

def test_case_execution(n):
    if n == 0:
        return
    x = int(input())
    ans = 0
    y = input().split()
    ans += sum_squares(x, y)
    print(ans)
    test_case_execution(n-1)

if __name__ == "__main__":
    main()