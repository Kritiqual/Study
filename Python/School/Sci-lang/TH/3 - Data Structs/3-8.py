d = {"0": 1.9, "1": 2.3, "2": 4.5, "3": 6.6}


def cnt(d):
    count = 0
    for i in d.values():
        if 2.5 <= i <= 3.5:
            count += 1
    return count


def addele(d):
    k = input("Nhap key = ")
    v = float(input("Nhap value: "))
    d[k] = v
    return d


def delele(d):
    dc = {k: v for k, v in d.items() if v >= 2.0}
    return dc


print(cnt(d))
d = addele(d)
print(d)
d = delele(d)
print(d)
