#include <bits/stdc++.h>
using namespace std;
//Phần xác định lớp, thuộc tính, phương thức ở cuối bài

class SanPham
{
private:
    string maSP, tenSP, tinhTrang;
    int donGia, Slg;

public:
    void Nhap();
    void Xuat();
    friend class Phieu;
};

void SanPham::Nhap()
{
    cout << "=================";
    cout << "\n - Nhap Ma SP: ";
    getline(cin, maSP);
    cout << " - Nhap Ten SP: ";
    getline(cin, tenSP);
    cout << " - Nhap Tinh trang: ";
    getline(cin, tinhTrang);
    cout << " - Nhap Don gia: ";
    cin >> donGia;
    cout << " - Nhap So luong: ";
    cin >> Slg;
}

void SanPham::Xuat()
{
    cout << left << setw(10) << maSP
         << left << setw(20) << tenSP
         << left << setw(12) << tinhTrang
         << left << setw(10) << donGia
         << left << setw(10) << Slg
         << left << setw(20) << donGia * Slg;
}

class NCC
{
private:
    string maNCC, tenNCC, diaChi, Sdt;

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
    cout << " - Nhap Sdt NCC: ";
    getline(cin, Sdt);
}

void NCC::Xuat()
{
    cout << left << "Ma NCC: "
         << left << setw(31) << maNCC
         << left << "Ten NCC: "
         << left << setw(10) << tenNCC
         << endl;

    cout << left << "Dia Chi: "
         << left << setw(30) << diaChi
         << left << "Sdt: "
         << left << setw(10) << Sdt
         << "\n\n";
}

class Phieu
{
private:
    string maPhieu;
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
    cout << "Dai Hoc Cong Nghiep Ha Noi";
    cout << "\n\t===== PHIEU NHAP THIET BI MAY TINH =====\n";
    cout << left << "Ma Phieu: " << maPhieu << endl;
    Ncc.Xuat();
    cout << left << setw(10) << "Ma SP"
         << left << setw(20) << "Ten San pham"
         << left << setw(12) << "Tinh trang"
         << left << setw(10) << "Don gia"
         << left << setw(10) << "So luong"
         << left << setw(20) << "Thanh tien";

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        SP[i].Xuat();
        sum += SP[i].donGia * SP[i].Slg;
    }
    cout << left << "Tong so san pham: "
         << setw(25) << n
         << left << "Tong so tien: " << sum << " dong"
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