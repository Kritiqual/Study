from pkg2.sub1 import *


def checknr(a, b, c):
    l = [dtO(a[0], a[1], 0, 0), dtO(b[0], b[1], 0, 0), dtO(c[0], c[1], 0, 0)]
    min = l[0]
    check = 0
    for i, v in enumerate(l):
        if min < v:
            min = v
            check = i
    if check == 1:
        return "A"
    elif check == 2:
        return "B"
    else:
        return "C"


def checkfr(a, b, c):
    l = [dtO(a[0], a[1], 0, 0), dtO(b[0], b[1], 0, 0), dtO(c[0], c[1], 0, 0)]
    max = l[0]
    check = 0
    for i, v in enumerate(l):
        if max > v:
            max = v
            check = i
    if check == 1:
        return "A"
    elif check == 2:
        return "B"
    else:
        return "C"
