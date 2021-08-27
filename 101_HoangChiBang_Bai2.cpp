#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

class TaiSan
{
private:
    string tenTS, tinhTrang;
    int Slg;

public:
    void SetInfo(string tenTS, int Slg, string tinhTrang)
    {
        this->tenTS = tenTS;
        this->Slg = Slg;
        this->tinhTrang = tinhTrang;
    }
    string GetTenTS()
    {
        return tenTS;
    }
    int GetSlg()
    {
        return Slg;
    }
    string GetTinhTrang()
    {
        return tinhTrang;
    }
};

class NhanVien
{
private:
    string hoTen, chucVu;

public:
    void SetInfo(string hoTen, string chucVu)
    {
        this->hoTen = hoTen;
        this->chucVu = chucVu;
    }
    string GetHoTen()
    {
        return hoTen;
    }
    string GetChucVu()
    {
        return chucVu;
    }
};

class Phong
{
private:
    string tenPhong, maPhong, truongPhong;

public:
    void SetInfo(string tenPhong, string maPhong, string truongPhong)
    {
        this->tenPhong = tenPhong;
        this->maPhong = maPhong;
        this->truongPhong = truongPhong;
    }
    string GetTenPhong()
    {
        return tenPhong;
    }
    string GetMaPhong()
    {
        return maPhong;
    }
    string GetTruongPhong()
    {
        return truongPhong;
    }
};

class Phieu
{
private:
    NhanVien NV;
    Phong Phg;
    TaiSan *TS;
    string maPhieu, ngayKiem, hoTenNV, chucVuNV, tenPhong, maPhong, truongPhong, tenTS, tinhTrang;
    int n, Slg;

public:
    string GetMaPhieu()
    {
        return maPhieu;
    }
    string GetNgayKiem()
    {
        return ngayKiem;
    }
    void Nhap();
    void Xuat();
    void Bonus1();
    void Bonus2(int pos);
    void Bonus3();
};

void Phieu::Nhap()
{
    cout << "Nhap Ma Phieu: ";
    getline(cin, this->maPhieu);
    cout << "Nhap Ngay Kiem: ";
    getline(cin, this->ngayKiem);

    cout << "Nhap Ho Ten NV: ";
    getline(cin, hoTenNV);
    cout << "Nhap Chuc Vu NV: ";
    getline(cin, chucVuNV);
    NV.SetInfo(hoTenNV, chucVuNV);

    cout << "Nhap Ten Phong: ";
    getline(cin, tenPhong);
    cout << "Nhap Ma Phong: ";
    getline(cin, maPhong);
    cout << "Nhap Truong Phong: ";
    getline(cin, truongPhong);
    Phg.SetInfo(tenPhong, maPhong, truongPhong);

    cout << "Nhap so luong Tai San: ";
    cin >> n;
    TS = new TaiSan[n];
    for (int i = 0; i < n; i++)
    {
        system("cls");
        fflush(stdin);
        cout << "=====================";
        cout << "\nSTT\t\t    " << i + 1;
        cout << "\nNhap Ten TS: ";
        getline(cin, tenTS);
        cout << "Nhap So luong: ";
        cin >> Slg;
        cout << "Nhap Tinh Trang: ";
        fflush(stdin);
        getline(cin, tinhTrang);
        TS[i].SetInfo(tenTS, Slg, tinhTrang);
    }
}

void Phieu::Xuat()
{
    // system("cls");
    cout << "\t\t\tPHIEU KIEM KE TAI SAN\n";
    cout << left << setw(20) << "\nMa phieu: "
         << left << setw(30) << GetMaPhieu()
         << left << setw(15) << "Ngay kiem ke:"
         << left << GetNgayKiem()
         << left << setw(20) << "\nNhan vien kiem ke:"
         << left << setw(30) << NV.GetHoTen()
         << left << setw(15) << "Chuc vu:"
         << left << NV.GetChucVu()
         << left << setw(20) << "\nKiem ke tai phong:"
         << left << setw(30) << Phg.GetTenPhong()
         << left << setw(15) << "Ma Phong:"
         << left << Phg.GetMaPhong()
         << left << setw(20) << "\nTruong phong:"
         << left << Phg.GetTruongPhong();

    cout << left << setw(32) << "\n\nTen tai san"
         << left << setw(20) << "So luong"
         << left << "Tinh trang";
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        cout << left << setw(30) << TS[i].GetTenTS()
             << left << setw(20) << TS[i].GetSlg()
             << left << TS[i].GetTinhTrang();
        sum += TS[i].GetSlg();
    }
    cout << left << "\n\nSo tai san da kiem ke: "
         << left << setw(25) << n
         << "Tong so luong: " << sum << endl;
}

void Phieu::Bonus1()
{
    system("pause");
    for (int i = 0; i < n; i++)
    {
        if (TS[i].GetTenTS() == "May vi tinh")
        {
            TS[i].SetInfo("May vi tinh", 20, TS[i].GetTinhTrang());
        }
    }
    Xuat();
}

void Phieu::Bonus2(int pos)
{
    system("pause");
    TS = (TaiSan *)realloc(TS, (n + 1) * sizeof(TaiSan));
    for (int i = n; i > pos - 1; i--)
    {
        TS[i] = TS[i - 1];
        cout << 10000;
    }
    n++;
    TS[pos - 1].SetInfo("Laptop", 10, "Tot");
    Xuat();
}

void Phieu::Bonus3()
{
}

int main()
{
    Phieu Phieu1;
    Phieu1.Nhap();
    Phieu1.Xuat();
    Phieu1.Bonus1();
    Phieu1.Bonus2(2);
}