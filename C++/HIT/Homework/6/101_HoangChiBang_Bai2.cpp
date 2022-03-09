#include <bits/stdc++.h>
using namespace std;

class DATE
{
private:
    int D, M, Y;

public:
    void Nhap();
    void Xuat();
};

void DATE::Nhap()
{
    cout << "Nhap Ngay nhap (d m y): ";
    cin >> D >> M >> Y;
}

void DATE::Xuat()
{
    cout << "\nNgay nhap: " << D << "/" << M << "/" << Y;
}

class NSX
{
private:
    string tenNSX, diaChi;

public:
    void Nhap();
    void Xuat();
};

void NSX::Nhap()
{
    cout << "Nhap Ten NSX: ";
    cin.ignore();
    getline(cin, tenNSX);
    cout << "Nhap Dia chi: ";
    getline(cin, diaChi);
}

void NSX::Xuat()
{
    cout << "\nTen NSX: " << tenNSX;
    cout << "\nDia chi: " << diaChi;
}

class HANG
{
private:
    string tenHang;
    NSX x;
    int donGia;

public:
    void Nhap();
    void Xuat();
    HANG();
};

HANG::HANG()
{
    tenHang = "";
    donGia = 0;
}

void HANG::Nhap()
{
    cout << "Nhap Ten hang: ";
    getline(cin, tenHang);
    x.Nhap();
    cout << "Nhap Don gia: ";
    cin >> donGia;
}

void HANG::Xuat()
{
    cout << "\nTen hang: " << tenHang;
    x.Xuat();
    cout << "\nDon gia: " << donGia << " dong";
}

class TIVI : public HANG
{
private:
    string kichThuoc;
    DATE ngayNhap;

public:
    void Nhap();
    void Xuat();
    TIVI();
};

TIVI::TIVI()
{
    kichThuoc = "";
}

void TIVI::Nhap()
{
    HANG::Nhap();
    ngayNhap.Nhap();
    cout << "Nhap Kich thuoc: ";
    cin.ignore();
    getline(cin, kichThuoc);
}

void TIVI::Xuat()
{
    HANG::Xuat();
    ngayNhap.Xuat();
    cout << "\nKich thuoc: " << kichThuoc << endl;
}

int main()
{
    TIVI tivi;
    tivi.Nhap();
    tivi.Xuat();
}