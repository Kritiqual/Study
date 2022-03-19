from mypkg.subpkg1.mod1 import *


def USD_to_VND(n):
    return int(n) * USD


def EUR_to_VND(n):
    return int(n) * EUR


def RUB_to_VND(n):
    return int(n) * RUB


def plus(a, b, c=None):
    if c == None:
        return a + b
    else:
        return a + b + c
