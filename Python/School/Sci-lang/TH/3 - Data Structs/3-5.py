def tfs():
    n = int(input("Nhap n = "))
    a = []
    for i in range(n):
        a.append(input(f"Nhap ky tu a[{i}] = "))
    return tuple(a)


def count(s):
    c = 0
    for i in s[:]:
        if i.isnumeric():
            c += 1


s = tfs()
print(s)
