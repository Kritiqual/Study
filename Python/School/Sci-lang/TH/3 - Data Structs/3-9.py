def ipt():
    S = input("Nhap xau S: ")
    Q = "I Love You"
    return S, Q


def mrge(S, Q):
    return S + Q


def checkS(S, Q):
    if Q.find(S) >= 0:
        print("S trong Q")
    else:
        print("S khong trong Q")


def rplc(S):
    s = S.replace("Ha", "Ba")
    return s


def splt(S):
    l = S.split()
    print(l)


S, Q = ipt()
checkS(S, Q)
print(mrge(S, Q))
print(rplc(S))
# print(splt(S))
