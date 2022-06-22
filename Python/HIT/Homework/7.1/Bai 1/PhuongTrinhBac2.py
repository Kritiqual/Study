import math


class PTB2:
    def __init__(self, a=0.0, b=0.0, c=0.0):
        self.__a = a
        self.__b = b
        self.__c = c

    def Ipt(self):
        self.__a = int(input("Nhap a = "))
        self.__b = int(input("Nhap b = "))
        self.__c = int(input("Nhap c = "))

    def Opt(self):
        print("{}x^2 + {}x + {} = 0".format(self.__a, self.__b, self.__c))

    def Solve(self):
        if self.__a == 0:
            if self.__b == 0:
                if self.__c == 0:
                    print("Phuong trinh vo so nghiem!")
                else:
                    print("Phuong trinh vo nghiem!")
            else:
                print("Phuong trinh co nghiem: x={}".format(-self.__c / self.__b))
        else:
            __delta = self.__b**2 - 4 * self.__a * self.__c
            if __delta < 0:
                print("Phuong trinh vo nghiem!")
            if __delta == 0:
                print(
                    "Phuong trinh co nghiem kep: x1 = x2 = {}".format(
                        -self.__b / (2 * self.__a)
                    )
                )
            if __delta > 0:
                print(
                    "Phuong trinh co 2 nghiem: x1 = {}; x2 = {}".format(
                        (-self.__b + math.sqrt(__delta)) / (2 * self.__a),
                        (-self.__b - math.sqrt(__delta)) / (2 * self.__a),
                    )
                )
