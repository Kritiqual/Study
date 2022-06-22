n, m = map(int, input("Nhap m va n: ").split())
a = []
for i in range(n):
    sub = []
    for j in range(m):
        sub.append(int(input(f"Nhap phan tu a[{i}][{j}]: ")))
    a.append(sub)