def vecinput():
    l = list(map(int, input("Nhập mảng: ").split()))
    return l


def vecsum(l):
    return sum(l)


def vecinsert(l):
    pos, k = map(int, input("Nhập vị trí và số cần chèn: ").split())
    l.insert(pos, k)
    return l


def vecdel(l):
    l.remove(int(input("Nhập phần tử cần xóa: ")))
    return l


def vecadd(a, b):
    l = []
    if len(a) != len(b):
        return l
    l = [sum(i) for i in zip(a, b)]
    return l
