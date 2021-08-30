#include <bits/stdc++.h>
using namespace std;
//Sơ đồ lớp ở file 101_Sơ_đồ_lớp_Bài_4.pdf

class DiaChi
{
private:
    int So, Ngo;
    string Pho, Phuong, Quan, tPho;

public:
    void Nhap();
    void Xuat();
    friend class Nguoi;
};

void DiaChi::Nhap()
{
    cout << "Dia Chi: ";
    cout << "\n - So: ";
    cin >> So;
    cout << " - Ngo: ";
    cin >> Ngo;
    cout << " - Pho: ";
    fflush(stdin);
    getline(cin, Pho);
    cout << " - Phuong: ";
    getline(cin, Phuong);
    cout << " - Quan: ";
    getline(cin, Quan);
    cout << " - Thanh pho: ";
    getline(cin, tPho);
}

void DiaChi::Xuat()
{
    cout << left << "So " << So
         << ", ngo " << Ngo
         << ", pho " << Pho
         << ", phuong " << Phuong
         << ", quan " << Quan
         << ", " << tPho
         << endl;
}

class NguoiDiCho
{
private:
    string hoTen, Sdt;
    DiaChi Dc;

public:
    void Nhap();
    void Xuat();
    friend class Phieu;
};

void NguoiDiCho::Nhap()
{
    cout << "Nguoi di Cho: ";
    cout << "\n - Ho Ten: ";
    getline(cin, hoTen);
    cout << " - So dien thoai: ";
    getline(cin, Sdt);
    Dc.Nhap();
}

void NguoiDiCho::Xuat()
{
    cout << left << setw(30) << "\nHo va ten nguoi di cho: " << hoTen << endl;
    cout << left << setw(20) << "So dien thoai: " << Sdt << endl;
    cout << left << setw(13) << "Dia chi: ";
    Dc.Xuat();
}

class Hang
{
private:
    string tenHang;
    int donGia, Slg;

public:
    void Nhap();
    void Xuat();
    friend class Phieu;
};

void Hang::Nhap()
{
    cout << "Nhap Ten Hang hoa: ";
    getline(cin, tenHang);
    cout << "Nhap So luong va Don gia: ";
    cin >> Slg >> donGia;
}

void Hang::Xuat()
{
    cout << left << setw(20) << tenHang
         << left << setw(9) << donGia
         << left << setw(11) << Slg
         << left << setw(12) << donGia * Slg;
}

class Phieu
{
private:
    string maPhieu, Ngay;
    NguoiDiCho Nguoi;
    Hang *hangHoa;
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
    cout << "Nhap Ngay di Cho: ";
    getline(cin, Ngay);
    Nguoi.Nhap();

    cout << "Nhap so luong hang hoa: ";
    cin >> n;
    hangHoa = new Hang[n];
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        system("cls");
        hangHoa[i].Nhap();
    }
}

void Phieu::Xuat()
{
    system("cls");
    cout << "\t\t~ PHIEU DI CHO ~\n\n";
    cout << left << setw(17) << "Ma Phieu: "
         << left << setw(20) << maPhieu
         << left << "Ngay: " << Ngay;
    Nguoi.Xuat();
    cout << endl
         << left << setw(20) << "Ten Hang"
         << left << setw(9) << "Don gia"
         << left << setw(11) << "So luong"
         << left << setw(12) << "Thanh tien";
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        hangHoa[i].Xuat();
        sum += hangHoa[i].donGia * hangHoa[i].Slg;
    }
    cout << endl
         << left << setw(15) << "\t\t\tCong thanh tien "
         << left << setw(20) << sum
         << endl;
}

int main()
{
    Phieu Phieu1;
    Phieu1.Nhap();
    Phieu1.Xuat();
}