#include <iostream>
#include <iomanip>
using namespace std;

class SinhVien
{
private:
    string maSV, hoTen, gioiTinh, daoDuc, NS;
    float Dtb;

public:
    SinhVien();
    SinhVien(string maSV, string hoTen, string NS, string gioiTinh, float Dtb, string daoDuc);
    ~SinhVien();
    void SetInfo(string maSV, string hoTen, string NS, string gioiTinh, float Dtb, string daoDuc)
    {
        this->maSV = maSV;
        this->hoTen = hoTen;
        this->NS = NS;
        this->gioiTinh = gioiTinh;
        this->Dtb = Dtb;
        this->daoDuc = daoDuc;
    }
    string GetMaSV()
    {
        return maSV;
    }
    string GetHoTen()
    {
        return hoTen;
    }
    string GetBirth()
    {
        return NS;
    }
    string GetGioiTinh()
    {
        return gioiTinh;
    }
    float GetDtb()
    {
        return Dtb;
    }
    string GetDaoDuc()
    {
        return daoDuc;
    }
};

SinhVien::SinhVien()
{
    maSV = "";
    hoTen = "";
    NS = "";
    gioiTinh = "";
    Dtb = 0;
    daoDuc = "";
}

SinhVien::~SinhVien()
{
    maSV = "";
    hoTen = "";
    NS = "";
    gioiTinh = "";
    Dtb = 0;
    daoDuc = "";
}

void NhapSV(SinhVien &SV)
{
    string maSV, hoTen, gioiTinh, daoDuc, NS;
    float Dtb;
    cout << "\nNhap Ma SV: ";
    getline(cin, maSV);
    cout << "Nhap Ho Ten SV: ";
    getline(cin, hoTen);
    cout << "Nhap Ngay Thang Nam sinh: ";
    getline(cin, NS);
    cout << "Nhap Gioi Tinh: ";
    getline(cin, gioiTinh);
    cout << "Nhap Diem TB: ";
    cin >> Dtb;
    cout << "Nhap Xep loai Dao duc: ";
    fflush(stdin);
    getline(cin, daoDuc);
    SV.SetInfo(maSV, hoTen, NS, gioiTinh, Dtb, daoDuc);
}

void XuatSV(SinhVien SV)
{
    cout << endl;
    cout << left << setw(12) << SV.GetMaSV()
         << left << setw(20) << SV.GetHoTen()
         << left << setw(12) << SV.GetBirth()
         << left << setw(10) << SV.GetGioiTinh()
         << left << setw(8) << SV.GetDtb()
         << left << setw(9) << SV.GetDaoDuc();
}

void InfoBar()
{
    cout << "\nDanh sach SV";
    cout << left << setw(12) << "\nMa SV"
         << left << setw(20) << "Ho va Ten"
         << left << setw(12) << "Ngay Sinh"
         << left << setw(10) << "Gioi Tinh"
         << left << setw(8) << "Diem TB"
         << left << setw(9) << "Xep loai";
}

int main()
{
    int n;
    cout << "Nhap so luong Sinh Vien: ";
    cin >> n;
    SinhVien *SV = new SinhVien[n];
    for (int i = 0; i < n; i++)
    {
        system("cls");
        cout << "Sinh vien thu " << i + 1
             << "\n---------------";
        fflush(stdin);
        NhapSV(SV[i]);
    }
    //Xuat
    system("cls");
    InfoBar();
    for (int i = 0; i < n; i++)
    {
        XuatSV(SV[i]);
    }

    //Xuat ra DS SV Tot
    InfoBar();
    for (int i = 0; i < n; i++)
    {
        if (SV[i].GetDaoDuc() == "Tot" || SV[i].GetDaoDuc() == "tot")
        {
            XuatSV(SV[i]);
        }
    }
}
