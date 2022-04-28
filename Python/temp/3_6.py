def cv(a):
    return tuple(float(ele) for ele in a)


def aft(a):
    s = 0
    for ele in a:
        s += ele
    return s / len(a)


a = ('123', '456', '789')
b = cv(a)
print(aft(b))
