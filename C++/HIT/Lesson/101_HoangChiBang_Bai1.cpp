#include <bits/stdc++.h>
using namespace std;

class NGUOI
{
protected:
    string hoTen, gTinh;
    int Tuoi;

public:
    void Nhap();
    void Xuat();
};

void NGUOI::Nhap()
{
    system("cls");
    fflush(stdin);
    cout << "Thong tin co ban: \n";
    cout << " - Ho ten: ";
    getline(cin, hoTen);
    cout << " - Tuoi: ";
    cin >> Tuoi;
    cout << " - Gioi tinh: ";
    fflush(stdin);
    getline(cin, gTinh);
}

void NGUOI::Xuat()
{
    cout << left << setw(25) << hoTen
         << left << setw(5) << Tuoi
         << left << setw(10) << gTinh;
}

class NHANVIEN : public NGUOI
{
private:
    string maNV, chucVu;
    int Luong;

public:
    void Nhap();
    void Xuat();
    friend class CONGTY;
};

void NHANVIEN::Nhap()
{
    NGUOI::Nhap();
    cout << "Thong tin NV: \n";
    cout << " - Ma NV: ";
    fflush(stdin);
    getline(cin, maNV);
    cout << " - Chuc vu: ";
    getline(cin, chucVu);
    cout << " - Luong: ";
    cin >> Luong;
    fflush(stdin);
}

void NHANVIEN::Xuat()
{
    NGUOI::Xuat();
    cout << left << setw(12) << maNV
         << left << setw(15) << chucVu
         << left << Luong;
}

class CONGTY
{
private:
    string maCT, diaChi;
    NHANVIEN *x;
    int n;

public:
    void Nhap();
    void Xuat();
    void Doi();
};

void CONGTY::Nhap()
{
    cout << "=====CONG TY=====";
    cout << "\n - Nhap Ma Cty: ";
    getline(cin, maCT);
    cout << " - Dia chi: ";
    getline(cin, diaChi);
    cout << "   > Nhap so luong nhan vien: ";
    cin >> n;
    x = new NHANVIEN[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhan vien thu " << i + 1 << endl;
        fflush(stdin);
        x[i].Nhap();
    }
}

void CONGTY::Xuat()
{
    system("cls");
    cout << "\n\t\t==========CONG TY XXX==========\n";
    cout << left << "Ma cong ty:" << setw(12) << maCT << endl;
    cout << left << "Dia chi: " << left << diaChi << endl;
    cout << left << setw(25) << "Ho va Ten"
         << left << setw(5) << "Tuoi"
         << left << setw(10) << "Gioi tinh"
         << left << setw(12) << "Ma NV"
         << left << setw(15) << "Chuc vu"
         << left << "Luong";
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        x[i].Xuat();
    }
}

void CONGTY::Doi()
{
    system("pause");
    for (int i = 0; i < n; i++)
    {
        if (x[i].Tuoi > 40 && x[i].chucVu == "ke toan")
        {
            x[i].Luong = 1000;
        }
    }
    CONGTY::Xuat();
}

int main()
{
    CONGTY ctyA;
    ctyA.Nhap();
    ctyA.Xuat();
    ctyA.Doi();
}