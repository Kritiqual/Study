from os import system
from mypkg.subpkg2.mod2 import *

if __name__ == "__main__":
    system("clear")

    x, y, z = map(float, input("Nhap gia tien: ").split())
    a, b, c = USD_to_VND(x), EUR_to_VND(y), RUB_to_VND(z)
    print(f"Tong: {plus(a, b, c)}")
