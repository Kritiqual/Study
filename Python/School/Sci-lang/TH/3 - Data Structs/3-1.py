import imp
from mymod import *
from os import system

system("clear")
a = vecinput()
print(f"Mảng đã nhập là: {a}")
print(f"Tổng của mảng: {vecsum(a)}")
print(f"Mảng sau khi chèn: {vecinsert(a)}")
print(f"Mảng sau khi xóa: {vecdel(a)}")
b = vecinput()
print(f"Tổng 2 mảng: {vecadd(a, b)}")
