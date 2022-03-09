// #include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>
// #include <conio.h>
using namespace std;
void pause(void)
{
    system("echo '\nPress any key to continue...' && ( read x 2> nul; rm nul || pause > nul )");
    return;
}
void cls(void)
{
    system("cls||clear");
    return;
}

class LOPHOC;
class NGUOI
{
protected:
    char hoTen[30], ngaySinh[12], queQuan[50];

public:
    void Nhap();
    void Xuat();
    friend void SX(LOPHOC &a);
};

void NGUOI::Nhap()
{
    cout << "Nhap Ho ten: ";
    cin.getline(hoTen, 30);
    cout << "Nhap Ngay sinh: ";
    cin.getline(ngaySinh, 12);
    cout << "Nhap Que quan: ";
    cin.getline(queQuan, 50);
}

void NGUOI::Xuat()
{
    cout << left << setw(20) << hoTen
         << left << setw(12) << ngaySinh
         << left << setw(30) << queQuan;
}

class SINHVIEN : public NGUOI
{
private:
    char maSV[10], Nganh[20];
    int khoaHoc;

public:
    void Nhap();
    void Xuat();
    friend void Dem(LOPHOC a);
    friend void SX(LOPHOC &a);
};

void SINHVIEN::Nhap()
{
    NGUOI::Nhap();
    cout << "Nhap Ma SV: ";
    cin.getline(maSV, 10);
    cout << "Nhap Nganh: ";
    cin.getline(Nganh, 20);
    cout << "Nhap Khoa hoc: ";
    cin >> khoaHoc;
    cin.ignore();
}

void SINHVIEN::Xuat()
{
    NGUOI::Xuat();
    cout << left << setw(12) << maSV
         << left << setw(20) << Nganh
         << left << khoaHoc << endl;
}

class LOPHOC
{
private:
    char maLH[10], tenLH[30], ngayMo[12], giaoVien[30];
    SINHVIEN *x;
    int n;

public:
    void Nhap();
    void Xuat();
    friend void Dem(LOPHOC a);
    friend void SX(LOPHOC &a);
};

void LOPHOC::Nhap()
{
    cls();
    cout << "Nhap Ma LH: ";
    cin.getline(maLH, 10);
    cout << "Nhap Ten LH: ";
    cin.getline(tenLH, 30);
    cout << "Nhap Ten GV: ";
    cin.getline(giaoVien, 30);
    cout << "Nhap So luong sinh vien: ";
    cin >> n;
    cin.ignore();
    x = new SINHVIEN[n];
    for (int i = 0; i < n; i++)
    {
        cls();
        cout << "STT: " << i + 1 << endl;
        x[i].Nhap();
    }
}

void LOPHOC::Xuat()
{
    cls();
    cout << "\t\t\t\t\tDANH SACH LOP HOC\n\n";
    cout << left << setw(7) << "Ma LH:" << left << setw(12) << maLH
         << left << setw(8) << "Ten LH:" << left << setw(32) << tenLH
         << left << setw(11) << "Giao vien:" << giaoVien << endl
         << left << setw(20) << "Ho ten SV"
         << left << setw(12) << "Ngay sinh"
         << left << setw(30) << "Que quan"
         << left << setw(12) << "Ma SV"
         << left << setw(20) << "Nganh"
         << left << "Khoa hoc" << endl;
    for (int i = 0; i < n; i++)
    {
        x[i].Xuat();
    }
}

void Dem(LOPHOC a)
{
    int count = 0;
    for (int i = 0; i < a.n; i++)
        if (a.x[i].khoaHoc == 11)
            count++;
    cout << "\nCo " << count << " sinh vien khoa 11" << endl;
}

void SX(LOPHOC &a)
{
    for (int i = 0; i < a.n; i++)
        for (int j = i + 1; j < a.n; j++)
            if (a.x[j].khoaHoc < a.x[i].khoaHoc)
                swap(a.x[i], a.x[j]);
    pause();
}

int main()
{
    LOPHOC a;
    a.Nhap();
    a.Xuat();
    Dem(a);
    SX(a);
    a.Xuat();
}