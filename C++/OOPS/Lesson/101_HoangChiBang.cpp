#include <iostream>
using namespace std;

class ConNguoi
{
private:
    char hoTen[30], ngaySinh[10], queQuan[50];

public:
    void NhapCng();
    void XuatCng();
};

void ConNguoi::NhapCng()
{
    cout << "Nhap Ho ten: ";
    fflush(stdin);
    gets(hoTen);
    cout << "Nhap Ngay sinh: ";
    gets(ngaySinh);
    cout << "Nhap Que quan: ";
    gets(queQuan);
}

void ConNguoi::XuatCng()
{
    cout << "Ho va Ten: " << hoTen << endl;
    cout << "Ngay sinh: " << ngaySinh << endl;
    cout << "Que quan: " << queQuan << endl;
}

class SinhVien : public ConNguoi
{
private:
    char tenTruong[30], chuyenNganh[20];
    int MSSV;

public:
    void Nhap();
    void Xuat();
};

void SinhVien::Nhap()
{
    ConNguoi::NhapCng();
    cout << "Nhap Ten truong: ";
    fflush(stdin);
    gets(tenTruong);
    cout << "Nhap Chuyen nganh: ";
    gets(chuyenNganh);
    cout << "Nhap MSSV: ";
    cin >> MSSV;
}

void SinhVien::Xuat()
{
    ConNguoi::XuatCng();
    cout << "Ten truong: " << tenTruong << endl;
    cout << "Chuyen nganh: " << chuyenNganh << endl;
    cout << "MSSV: " << MSSV << endl;
}

int main()
{
    SinhVien SVa;
    SVa.Nhap();
    SVa.Xuat();
}