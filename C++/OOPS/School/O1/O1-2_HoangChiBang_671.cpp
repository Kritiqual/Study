// #include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>
#include <cmath>
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

class PHIEU;
class MONHOC
{
private:
    char tenMH[30];
    int soTin;
    float diemMH;

public:
    void Nhap();
    void Xuat();
    MONHOC(){};
    MONHOC(char tenMH[], int soTin, float diemMH);
    friend class PHIEU;
    friend void SoTing3(PHIEU p);
    friend void ChenMH(PHIEU &p, MONHOC MH);
};

MONHOC::MONHOC(char tenMH[], int soTin, float diemMH)
{
    strcpy(this->tenMH, tenMH);
    this->soTin = soTin;
    this->diemMH = diemMH;
}

void MONHOC::Nhap()
{
    cout << "Nhap Ten MH: ";
    cin.getline(tenMH, 30);
    cout << "Nhap So trinh: ";
    cin >> soTin;
    cout << "Nhap Diem: ";
    cin >> diemMH;
    cin.ignore();
}

void MONHOC::Xuat()
{
    cout << left << setw(30) << tenMH
         << left << setw(10) << soTin
         << left << diemMH << endl;
}

class PHIEU
{
private:
    char maSV[10], tenSV[30], Lop[30];
    int Khoa, n;
    MONHOC *MH;

public:
    void Nhap();
    void Xuat();
    friend void SoTing3(PHIEU p);
    friend void ChenMH(PHIEU &p, MONHOC MH);
};

void PHIEU::Nhap()
{
    cls();
    cout << "Nhap Ma SV: ";
    cin.getline(maSV, 10);
    cout << "Nhap Ten SV: ";
    cin.getline(tenSV, 30);
    cout << "Nhap Lop: ";
    cin.getline(Lop, 30);
    cout << "Nhap Khoa: ";
    cin >> Khoa;
    cout << "Nhap So Mon hoc: ";
    cin >> n;
    cin.ignore();
    MH = new MONHOC[n];
    for (int i = 0; i < n; i++)
    {
        cls();
        cout << "=== STT: " << i + 1 << " ===" << endl;
        MH[i].Nhap();
    }
}

void PHIEU::Xuat()
{
    cls();
    cout << "\t\tPHIEU BAO DIEM\n\n";
    cout << left << setw(15) << "Ma sinh vien: " << left << setw(12) << maSV
         << left << setw(15) << "Ten sinh vien: " << tenSV << endl
         << left << setw(15) << "Lop: " << left << setw(12) << Lop
         << left << setw(15) << "Khoa: " << Khoa << endl
         << left << "Bang diem: " << endl
         << left << setw(30) << "Ten mon"
         << left << setw(10) << "So trinh"
         << left << "Diem" << endl;
    float tongdiem = 0;
    float tongtin = tongdiem;
    for (int i = 0; i < n; i++)
    {
        MH[i].Xuat();
        tongdiem += MH[i].diemMH * MH[i].soTin;
        tongtin += MH[i].soTin;
    }
    cout << left << setw(15) << "\t\t\tDiem trung binh " << setprecision(3) << (float)tongdiem / tongtin;
}

void SoTing3(PHIEU p)
{
    cout << "\n\nCac mon co so trinh lon hon 3: ";
    int count = 0;
    for (int i = 0; i < p.n; i++)
        if (p.MH[i].soTin > 3)
        {
            cout << p.MH[i].tenMH << " ";
            count++;
        }
        else
            count = 0;
    if (count == 0)
        cout << "Khong co";
}

void ChenMH(PHIEU &p, MONHOC MH) // Chen vao cuoi danh sach
{
    p.MH = (MONHOC *)realloc(p.MH, (p.n + 1) * sizeof(MONHOC));
    p.MH[p.n] = MH;
    p.n++;
}

int main()
{
    PHIEU p;
    p.Nhap();
    p.Xuat();

    SoTing3(p);
    MONHOC MHC("MH bi chen", 10, 10);
    ChenMH(p, MHC);
    p.Xuat();
}