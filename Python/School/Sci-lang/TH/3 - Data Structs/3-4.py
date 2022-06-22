def MSL(a, b):
    c = []
    for i in b[::-1]:
        a.append(i)
    print(a)
    for i in range(len(a)):
        c.append(a[i])
        c.append(a[-i])
    return c


a = list(map(int, input("Nhập mảng a: ").split()))
b = list(map(int, input("Nhập mảng b: ").split()))
print(MSL(a, b))
