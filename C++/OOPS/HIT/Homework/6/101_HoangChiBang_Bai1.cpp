#include <bits/stdc++.h>
using namespace std;

class VEHICLE
{
protected:
    string nhanHieu, Hang;
    int namSX;

public:
    void Nhap();
    void Xuat();
};

void VEHICLE::Nhap()
{
    cout << "Nhap Nhan hieu: ";
    getline(cin, nhanHieu);
    cout << "Nhap Nam SX: ";
    cin >> namSX;
    cout << "Nhap Hang: ";
    cin.ignore();
    getline(cin, Hang);
}

void VEHICLE::Xuat()
{
    cout << "\nNhan hieu: " << nhanHieu;
    cout << "\nNam SX: " << namSX;
    cout << "\nHang: " << Hang;
}

class OTO : public VEHICLE
{
private:
    long soCho, dungTich;

public:
    void Nhap();
    void Xuat();
};

void OTO::Nhap()
{
    VEHICLE::Nhap();
    cout << "Nhap So cho ngoi: ";
    cin >> soCho;
    cout << "Nhap Dung tich: ";
    cin >> dungTich;
}

void OTO::Xuat()
{
    VEHICLE::Xuat();
    cout << "\nSo cho ngoi: " << soCho;
    cout << "\nDung tich: " << dungTich;
}

class MOTO : public VEHICLE
{
private:
    long phanKhoi;

public:
    void Nhap();
    void Xuat();
};

void MOTO::Nhap()
{
    cin.ignore();
    VEHICLE::Nhap();
    cout << "Nhap Phan khoi: ";
    cin >> phanKhoi;
}

void MOTO::Xuat()
{
    VEHICLE::Xuat();
    cout << "\nPhan khoi: " << phanKhoi;
}

int main()
{
    OTO oto;
    MOTO moto;
    oto.Nhap();
    moto.Nhap();

    oto.Xuat();
    moto.Xuat();
}