from pkg2.sub1 import *


def ABC(a, b, c):
    x = dtO(a[0], a[1], b[0], b[1])
    y = dtO(b[0], b[1], c[0], c[1])
    z = dtO(c[0], c[1], a[0], a[1])
    if x + y > z and y + z > x and x + z > y:
        p = (x + y + z) / 2
        return sqrt(p * (p - x) * (p - y) * (p - z))
