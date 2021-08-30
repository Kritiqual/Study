#include <bits/stdc++.h>
using namespace std;

class DATE
{
private:
    int d, m, y;

public:
    void Nhap();
    void Xuat();
    friend class NhanSu;
};

void DATE::Nhap()
{
    cout << "\n - Nhap Ngay: ";
    cin >> this->d;
    cout << " - Nhap Thang: ";
    cin >> this->m;
    cout << " - Nhap Nam: ";
    cin >> this->y;
}

void DATE::Xuat()
{
    cout << d << "/" << m << "/" << y;
}

class NhanSu
{
private:
    char hoTen[30];
    DATE NS;

public:
    static int maNhanSu;
    static int clone_maNhanSu;
    void Nhap();
    void Xuat();
};
int NhanSu::maNhanSu = 1;
int NhanSu::clone_maNhanSu = 1;

void NhanSu::Nhap()
{
    cout << "=============";
    cout << "\nMa Nhan Su: " << this->maNhanSu++;
    cout << "\nNhap Ho Ten: ";
    fflush(stdin);
    gets(this->hoTen);
    cout << "Nhap Date:";
    NS.Nhap();
}

void NhanSu::Xuat()
{
    cout << endl;
    cout << left << setw(12) << this->clone_maNhanSu++
         << left << setw(32) << this->hoTen;
    NS.Xuat();
}

int main()
{
    //Khoi tao
    int n;
    cout << "Nhap so Nhan Su: ";
    cin >> n;
    NhanSu *a = new NhanSu[n];

    //Nhap
    for (int i = 0; i < n; i++)
    {
        a[i].Nhap();
        cout << endl;
    }

    //Xuat
    cout << "\t\t====DANH SACH NHAN SU====\n\n";
    cout << left << setw(12) << "Ma Nhan Su"
         << left << setw(32) << "Ho va Ten"
         << left << setw(12) << "Ngay Sinh";
    for (int i = 0; i < n; i++)
    {
        a[i].Xuat();
    }
}