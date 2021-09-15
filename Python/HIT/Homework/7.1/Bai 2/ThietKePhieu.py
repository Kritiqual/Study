from os import system


class SinhVien:
    def __init__(self, maSV="", tenSV="", Lop="", Khoa=0):
        self.maSV = maSV
        self.tenSV = tenSV
        self.Lop = Lop
        self.Khoa = Khoa

    def Ipt(self):
        self.maSV = input("Nhap Ma SV: ")
        self.tenSV = input("Nhap Ten SV: ")
        self.Lop = input("Nhap Lop: ")
        self.Khoa = input("Nhap Khoa: ")

    def Opt(self):
        print("Ma sinh vien: {:<10}".format(self.maSV), end="")
        print("Ten sinh vien: {}".format(self.tenSV))
        print("Lop: {:<20}".format(self.Lop), end="")
        print("Khoa: {}".format(self.Khoa))


class MonHoc:
    def __init__(self, tenMon="", soTrinh=0, Diem=0):
        self.tenMon = tenMon
        self.soTrinh = soTrinh
        self.Diem = Diem

    def Ipt(self):
        system("clear")
        self.tenMon = input("Nhap Ten mon hoc: ")
        self.soTrinh = int(input("Nhap So trinh: "))
        self.Diem = int(input("Nhap Diem: "))

    def Opt(self):
        print("{:<25} {:<20} {}".format(self.tenMon, self.soTrinh, self.Diem))


class Phieu:
    dsMonhoc = []

    def Ipt(self):
        self.sinhVien = SinhVien()
        self.sinhVien.Ipt()
        for _ in range(int(input("Nhap So luong mon hoc: "))):
            monHoc = MonHoc()
            monHoc.Ipt()
            self.dsMonhoc.append(monHoc)

    def Opt(self):
        system("clear")
        print("{:^50}".format("PHIEU BAO DIEM"))
        self.sinhVien.Opt()
        print(
            "{} \n{:<25} {:<20} {}".format("Bang diem:", "Ten mon", "So trinh", "Diem")
        )
        for monHoc in self.dsMonhoc:
            monHoc.Opt()

        count = Sum = 0
        for monHoc in self.dsMonhoc:
            Sum += monHoc.soTrinh * monHoc.Diem
            count += monHoc.soTrinh
        print("Diem trung binh: {:.5f}".format(Sum / count))
