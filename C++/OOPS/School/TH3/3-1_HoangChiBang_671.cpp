// #include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>
// #include <conio.h>
using namespace std;
void pause(void)
{
    system("echo '\nPress any key to continue...' && ( read x 2> nul; rm nul || pause > nul )");
    return;
}
void cls(void)
{
    system("cls||clear");
    return;
}

class SINHVIEN
{
private:
    char maSV[10], hoTen[30];
    float diemToan, diemLy, diemHoa;

public:
    void Nhap();
    void Xuat();
    friend void Sap(SINHVIEN *sv, int n);
    friend float Tong(SINHVIEN sv);
};

void SINHVIEN::Nhap()
{
    cout << "Nhap Ma SV: ";
    cin.getline(maSV, 10);
    cout << "Nhap Ho ten SV: ";
    cin.getline(hoTen, 10);
    cout << "Nhap Diem Toan: ";
    cin >> diemToan;
    cout << "Nhap Diem Ly: ";
    cin >> diemLy;
    cout << "Nhap Diem Hoa: ";
    cin >> diemHoa;
    cin.ignore();
}

void SINHVIEN::Xuat()
{
    cout << left << setw(12) << maSV
         << left << setw(27) << hoTen
         << left << setw(10) << diemToan
         << left << setw(10) << diemLy
         << left << setw(10) << diemHoa;
}

float Tong(SINHVIEN sv)
{
    return sv.diemHoa + sv.diemLy + sv.diemToan;
}

void Sap(SINHVIEN *sv, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (Tong(sv[i]) > Tong(sv[j]))
                swap(sv[i], sv[j]);
        }
}

int main()
{
    cls();
    SINHVIEN *sv;
    int n;
    cout << "Nhap So luong sinh vien: ";
    cin >> n;
    sv = new SINHVIEN[n];
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cls();
        cout << "=== STT: " << i + 1 << " ===" << endl;
        sv[i].Nhap();
    }

    Sap(sv, n);
    cls();
    cout << "\t\t\tDANH SACH SINH VIEN\n";
    cout << left << setw(12) << "Ma SV"
         << left << setw(27) << "Ho ten SV"
         << left << setw(10) << "Diem Toan"
         << left << setw(10) << "Diem Ly"
         << left << setw(10) << "Diem Hoa"
         << left << "Tong diem" << endl;
    float tong = 0;
    for (int i = 0; i < n; i++)
    {
        sv[i].Xuat();
        cout << Tong(sv[i]) << endl;
    }
}