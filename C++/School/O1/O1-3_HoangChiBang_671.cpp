// #include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstring>
#include <cmath>
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

class PHIEU;
class TAISAN
{
private:
    char tenTS[30], conTS[10];
    int Slg;

public:
    void Nhap();
    void Xuat();
    friend class PHIEU;
    friend void Sua(PHIEU &p);
};

void TAISAN::Nhap()
{
    cout << "Nhap Ten TS: ";
    cin.getline(tenTS, 30);
    cout << "Nhap So luong: ";
    cin >> Slg;
    cin.ignore();
    cout << "Nhap Tinh trang: ";
    cin.getline(conTS, 10);
}

void TAISAN::Xuat()
{
    cout << left << setw(25) << tenTS
         << left << setw(17) << Slg
         << left << conTS << endl;
}

class NHANVIEN
{
private:
    char tenNV[30], chucVu[20];

public:
    void Nhap();
    void Xuat();
};

void NHANVIEN::Nhap()
{
    cout << "Nhap Ten NV: ";
    cin.getline(tenNV, 30);
    cout << "Nhap Chuc vu: ";
    cin.getline(chucVu, 20);
}

void NHANVIEN::Xuat()
{
    cout << left << setw(20) << "Nhan vien kiem ke: " << left << setw(22) << tenNV
         << left << setw(15) << "Chuc vu: " << chucVu << endl;
}

class PHONG
{
private:
    char tenPhong[30], maPhong[10], truongPhong[30];

public:
    void Nhap();
    void Xuat();
};

void PHONG::Nhap()
{
    cout << "Nhap Ten phong: ";
    cin.getline(tenPhong, 30);
    cout << "Nhap Ma phong: ";
    cin.getline(maPhong, 10);
    cout << "Nhap Truong phong: ";
    cin.getline(truongPhong, 30);
}

void PHONG::Xuat()
{
    cout << left << setw(20) << "Kiem ke tai phong: " << left << setw(22) << tenPhong
         << left << setw(15) << "Ma phong: " << left << maPhong << endl
         << left << setw(20) << "Truong phong: " << left << truongPhong << "\n\n";
}

class PHIEU
{
private:
    char maPhieu[10], ngayKK[12];
    NHANVIEN nv;
    PHONG pg;
    int n;
    TAISAN *ts;

public:
    void Nhap();
    void Xuat();
    friend void Sua(PHIEU &p);
};

void PHIEU::Nhap()
{
    cls();
    cout << "Nhap Ma Phieu: ";
    cin.getline(maPhieu, 10);
    cout << "Nhap Ngay kiem ke: ";
    cin.getline(ngayKK, 12);
    nv.Nhap();
    pg.Nhap();
    cout << "Nhap So Tai san: ";
    cin >> n;
    cin.ignore();
    ts = new TAISAN[n];
    for (int i = 0; i < n; i++)
    {
        cls();
        cout << "=== STT: " << i + 1 << " ===" << endl;
        ts[i].Nhap();
    }
}

void PHIEU::Xuat()
{
    cls();
    cout << "\t\tPHIEU KIEM KE TAI SAN\n\n";
    cout << left << setw(20) << "Ma phieu: " << left << setw(22) << maPhieu
         << left << setw(15) << "Ngay kiem ke: " << left << ngayKK << endl;
    nv.Xuat();
    pg.Xuat();
    cout << left << setw(25) << "Ten tai san"
         << left << setw(17) << "So luong"
         << left << "Tinh trang" << endl;
    int countTS = 0;
    for (int i = 0; i < n; i++)
    {
        ts[i].Xuat();
        countTS += ts[i].Slg;
    }
    cout << "\nSo tai san da kiem ke: " << left << setw(19) << n
         << "Tong so luong: " << countTS << endl;
}

void Sua(PHIEU &p)
{
    for (int i = 0; i < p.n; i++)
        if (strcmp(p.ts[i].tenTS, "May vi tinh") == 0)
            p.ts[i].Slg = 20;
    pause();
}

int main()
{
    PHIEU p;
    p.Nhap();
    p.Xuat();
    Sua(p);
    p.Xuat();
}