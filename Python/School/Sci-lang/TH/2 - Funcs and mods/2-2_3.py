from pkg1 import *

m, p = map(float, input("Nhập số dặm bay và số tiền: ").split())
print(
    f"Số tiền phải trả: {m*p} (VND) = {UtV(m*p)} (USD) = {EtV(m*p)} (EUR) = {RtV(m*p)} (RUB)"
)
