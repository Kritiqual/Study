#include <bits/stdc++.h>
using namespace std;
//Phần xác định lớp, thuộc tính, phương thức ở cuối bài

class SanPham
{
private:
    string tenSP;
    int donGia, Slg;

public:
    void Nhap();
    void Xuat();
    friend class Phieu;
};

void SanPham::Nhap()
{
    cout << "=================";
    cout << "\n - Nhap Ten SP: ";
    getline(cin, tenSP);
    cout << " - Nhap Don Gia: ";
    cin >> donGia;
    cout << " - Nhap So Luong: ";
    cin >> Slg;
}

void SanPham::Xuat()
{
    cout << left << setw(20) << tenSP
         << left << setw(10) << donGia
         << left << setw(10) << Slg
         << left << setw(20) << donGia * Slg;
}

class NCC
{
private:
    string maNCC, tenNCC, diaChi;

public:
    void Nhap();
    void Xuat();
    friend class Phieu;
};

void NCC::Nhap()
{
    cout << "NCC:";
    cout << "\n - Nhap Ma NCC: ";
    getline(cin, maNCC);
    cout << " - Nhap Ten NCC: ";
    getline(cin, tenNCC);
    cout << " - Nhap Dia Chi NCC: ";
    getline(cin, diaChi);
}

void NCC::Xuat()
{
    cout << left << "Ma NCC: "
         << left << setw(17) << maNCC
         << left << "Ten NCC: "
         << left << setw(10) << tenNCC
         << endl;

    cout << left << "Dia Chi: " << diaChi
         << endl;
}

class Phieu
{
private:
    string maPhieu, ngayLap;
    NCC Ncc;
    SanPham *SP;
    int n;

public:
    void Nhap();
    void Xuat();
};

void Phieu::Nhap()
{
    fflush(stdin);
    cout << "Nhap Ma Phieu: ";
    getline(cin, maPhieu);
    cout << "Nhap Ngay Lap Phieu: ";
    getline(cin, ngayLap);
    Ncc.Nhap();
    cout << "Nhap so luong SP: ";
    cin >> n;
    SP = new SanPham[n];
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        system("cls");
        SP[i].Nhap();
    }
}

void Phieu::Xuat()
{
    system("cls");
    cout << "\t===== PHIEU NHAP HANG =====\n\n";
    cout << left << "Ma Phieu: "
         << left << setw(15) << maPhieu 
         << left << "Ngay lap: " 
         << left << setw(10) << ngayLap 
         << endl;
    Ncc.Xuat();
    cout << left << setw(20) << "Ten hang"
         << left << setw(10) << "Don gia" 
         << left << setw(10) << "So luong" 
         << left << setw(20) << "Thanh tien" 
         << endl;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        SP[i].Xuat();
        sum += SP[i].donGia * SP[i].Slg;
        cout << endl;
    }
    cout << left << setw(17) << "\t\t\tCong thanh tien " 
         << left << setw(20) << sum 
         << endl;
}

int main()
{
    Phieu phieu1;
    phieu1.Nhap();
    phieu1.Xuat();
}

/*
Phiếu gồm: 
 - Mã Phiếu
 - Ngày lập

 - Nhà cung cấp:
    + Mã Nhà cung cấp
    + Tên Nhà cung cấp
    + Địa chỉ Nhà cung cấp
    + Nhập(), Xuất() (Của Nhà cung cấp)

 - Sản phẩm: 
    + Tên Sản phẩm
    + Đơn giá
    + Số lượng
    + Nhập(), Xuất() (Của Sản phẩm)

 - Nhập(), Xuất() (Của phiếu)
*/