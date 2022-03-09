#include <bits/stdc++.h>

using namespace std;
class PHIEU;

class NHANVIEN
{
    char HOTENNV[30];
    char CHUCVUNV[30];

public:
    void nhap();
    void xuat();
};
void NHANVIEN::nhap()
{
    cout << "Ho ten NV: ";
    fflush(stdin);
    gets(HOTENNV);
    cout << "Chuc vu  : ";
    fflush(stdin);
    gets(CHUCVUNV);
}
void NHANVIEN::xuat()
{
    cout << "Nhan vien kiem ke: " << HOTENNV;
    cout << "Chuc vu : " << CHUCVUNV << endl;
}

class PHONG
{
    char MAP[30];
    char TENP[30];
    char TENTP[30];

public:
    void nhap();
    void xuat();
};
void PHONG::nhap()
{
    cout << "Ma phong : ";
    fflush(stdin);
    gets(MAP);
    cout << "Ten phong: ";
    fflush(stdin);
    gets(TENP);
    cout << "Ten TP   : ";
    fflush(stdin);
    gets(TENTP);
}

void PHONG::xuat()
{
    cout << "Kiem ke tai phong: " << TENP;
    cout << "Ma phong : " << MAP << endl;
    cout << "Truong phong :" << TENTP << endl;
}

class TAISAN
{
    char TENTS[30];
    int SL;
    char TINHTRANG[30];

public:
    void nhap();
    void xuat();
    friend class PHIEU;
    friend void TIMKIEM(PHIEU k);
    friend void SAP(PHIEU k);
};
void TAISAN::nhap()
{
    cout << "Ten tai san : ";
    fflush(stdin);
    gets(TENTS);
    cout << "So luong    : ";
    cin >> SL;
    cout << "Tinh trang  : ";
    fflush(stdin);
    gets(TINHTRANG);
}
void TAISAN::xuat()
{
    cout << setw(20) << TENTS << setw(20) << SL << setw(20) << TINHTRANG << endl;
}

class PHIEU
{
    char MAPH[30];
    char NGAY[30];
    NHANVIEN x;
    PHONG y;
    TAISAN *z;
    int n;

public:
    void nhap();
    void xuat();
    friend void TIMKIEM(PHIEU k);
    friend void SAP(PHIEU k);
};
void PHIEU::nhap()
{
    cout << "Ma phieu : ";
    fflush(stdin);
    gets(MAPH);
    cout << "Ngay     : ";
    fflush(stdin);
    gets(NGAY);
    x.nhap();
    y.nhap();
    cout << "n=";
    cin >> n;
    z = new TAISAN[n];
    for (int i = 0; i < n; i++)
        z[i].nhap();
}
void PHIEU::xuat()
{
    cout << setw(40) << "PHIEU KIEM KE TAI SAN" << endl;
    cout << "Ma phieu : " << MAPH << ". Ngay kiem ke: " << NGAY << endl;
    x.xuat();
    y.xuat();
    cout << setw(20) << "Ten tai san" << setw(20) << "So luong" << setw(20) << "Tinh trang" << endl;
    for (int i = 0; i < n; i++)
        z[i].xuat();
    cout << "So tai san da kiem ke: " << n;

    int T = 0;
    for (int i = 0; i < n; i++)
        T = T + z[i].SL;
    cout << "Tong so luong: " << T << endl;
}

void TIMKIEM(PHIEU k)
{
    int d = 0;
    for (int i = 0; i < k.n; i++)
        if (strcmp(k.z[i].TENTS, "MAY TINH") == 0)
            d++;
    if (d == 0)
        cout << "KHONG CO MAY TINH" << endl;
    else
        cout << "CO MAY TINH" << endl;
}
void SAP(PHIEU k)
{
    for (int i = 0; i < k.n; i++)
        for (int j = i + 1; j < k.n; j++)
            if (k.z[i].SL > k.z[j].SL)
                swap(k.z[i], k.z[j]);
}
int main()
{
    PHIEU k;
    k.nhap();
    k.xuat();
    TIMKIEM(k);
    SAP(k);
    k.xuat();
}
