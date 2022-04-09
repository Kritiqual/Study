from pkg2 import *

a = list(map(float, input("Nhập tọa độ điểm A: ").split()))
b = list(map(float, input("Nhập tọa độ điểm B: ").split()))
c = list(map(float, input("Nhập tọa độ điểm C: ").split()))

print(f"Điểm gần O nhất: {checknr(a, b, c)}")
print(f"Điểm xa O nhất: {checkfr(a, b, c)}")

print(f"Diện tích tam giác ABC: {ABC(a, b, c):.5f}")
