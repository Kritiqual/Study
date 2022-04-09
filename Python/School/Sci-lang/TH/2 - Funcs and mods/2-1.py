from os import system


def isPrime(x):
    if x < 2:
        return False
    for i in range(2, int(x**2) + 1):
        if x % i == 0:
            return False
    return True


def isPalindrome(x):
    return str(x) == str(x)[::-1]


S, E = map(int, input("Nhap S, E: ").split())
while S >= E:
    system("clear")
    S, E = map(int, input("Nhap S, E: ").split())

s = sum([i for i in range(S, E + 1) if isPrime(i) and isPalindrome(i)])
print(f"Tổng các số thỏa mãn là: {s}")
