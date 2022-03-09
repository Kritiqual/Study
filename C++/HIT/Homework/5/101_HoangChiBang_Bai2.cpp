#include <bits/stdc++.h>
using namespace std;

class TaiSan
{
private:
    char tenTS[30], tinhTrang[20];
    int Slg;

public:
    TaiSan(){};
    TaiSan(char tenTS[30], int Slg, char tinhTrang[20]);
    void Nhap();
    void Xuat();
    friend class Phieu;
};

TaiSan::TaiSan(char tenTS[30], int Slg, char tinhTrang[20])
{
    strcpy(this->tenTS, tenTS);
    this->Slg = Slg;
    strcpy(this->tinhTrang, tinhTrang);
}

void TaiSan::Nhap()
{
    cout << "\nNhap Ten TS: ";
    gets(tenTS);
    cout << "Nhap So luong: ";
    cin >> Slg;
    cout << "Nhap Tinh Trang: ";
    fflush(stdin);
    gets(tinhTrang);
}

void TaiSan::Xuat()
{
    cout << endl;
    cout << left << setw(30) << tenTS
         << left << setw(20) << Slg
         << left << tinhTrang;
}

class NhanVien
{
private:
    string hoTen, chucVu;

public:
    void Nhap();
    void Xuat();
};

void NhanVien::Nhap()
{
    cout << "Nhap Ho Ten NV: ";
    getline(cin, hoTen);
    cout << "Nhap Chuc Vu NV: ";
    getline(cin, chucVu);
}

void NhanVien::Xuat()
{
    cout << left << setw(20) << "\nNhan vien kiem ke:"
         << left << setw(30) << hoTen
         << left << setw(15) << "Chuc vu:"
         << left << chucVu;
}

class Phong
{
private:
    string tenPhong, maPhong, truongPhong;

public:
    void Nhap();
    void Xuat();
};

void Phong::Nhap()
{
    cout << "Nhap Ten Phong: ";
    getline(cin, tenPhong);
    cout << "Nhap Ma Phong: ";
    getline(cin, maPhong);
    cout << "Nhap Truong Phong: ";
    getline(cin, truongPhong);
}

void Phong::Xuat()
{
    cout << left << setw(20) << "\nKiem ke tai phong:"
         << left << setw(30) << tenPhong
         << left << setw(15) << "Ma Phong:"
         << left << maPhong
         << left << setw(20) << "\nTruong phong:"
         << left << truongPhong;
}

class Phieu
{
private:
    string maPhieu, ngayKiem;
    NhanVien NV;
    Phong Phg;
    TaiSan *TS;
    int n;

public:
    void Nhap();
    void Xuat();
    void Bonus1();
    // void Bonus2(TaiSan x, int pos);
};

void Phieu::Nhap()
{
    cout << "Nhap Ma Phieu: ";
    getline(cin, maPhieu);
    cout << "Nhap Ngay Kiem: ";
    getline(cin, ngayKiem);
    NV.Nhap();
    Phg.Nhap();

    cout << "Nhap so luong Tai San: ";
    cin >> n;
    TS = new TaiSan[n];
    for (int i = 0; i < n; i++)
    {
        system("cls");
        fflush(stdin);
        cout << "=====================";
        cout << "\nSTT\t\t    " << i + 1;
        TS[i].Nhap();
    }
}

void Phieu::Xuat()
{
    // system("cls");
    cout << "\t\t\tPHIEU KIEM KE TAI SAN\n";
    cout << left << setw(20) << "\nMa phieu: "
         << left << setw(30) << maPhieu
         << left << setw(15) << "Ngay kiem ke:"
         << left << ngayKiem;
    NV.Xuat();
    Phg.Xuat();

    cout << left << setw(32) << "\n\nTen tai san"
         << left << setw(20) << "So luong"
         << left << "Tinh trang";
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        TS[i].Xuat();
        sum += TS[i].Slg;
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
        if (TS[i].tenTS == "May vi tinh" || TS[i].tenTS == "may vi tinh")
        {
            TS[i].Slg = 20;
        }
    }
    Xuat();
}

// void Phieu::Bonus2(TaiSan x, int pos)
// {
//     system("pause");
//     TS = (TaiSan *)realloc(TS, (n + 1) * sizeof(TaiSan));
//     for (int i = n; i > pos - 1; i--)
//     {
//         TS[i] = TS[i - 1];
//         cout << 10000;
//     }
//     n++;
//     TS[pos - 1] = x;
//     Xuat();
// }

int main()
{
    Phieu Phieu1;
    Phieu1.Nhap();
    Phieu1.Xuat();
    Phieu1.Bonus1();
    // TaiSan x("Laptop", 10, "Tot");
    // Phieu1.Bonus2(x, 2);
}