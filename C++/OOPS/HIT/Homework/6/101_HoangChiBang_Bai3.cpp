#include <bits/stdc++.h>
using namespace std;

class ELECTRONIC
{
protected:
    int congSuat, dienAp;

public:
    ELECTRONIC(){};
    ELECTRONIC(int congSuat, int dienAp);
};

ELECTRONIC::ELECTRONIC(int congSuat, int dienAp)
{
    this->congSuat = congSuat;
    this->dienAp = dienAp;
}

class MAYGIAT : public ELECTRONIC
{
private:
    int dungTich;
    string Loai;

public:
    MAYGIAT(){};
    MAYGIAT(int dungTich, string Loai, int congSuat, int dienAp);
    void Xuat();
};

MAYGIAT::MAYGIAT(int dungTich, string Loai, int congSuat, int dienAp)
{
    this->dungTich = dungTich;
    this->Loai = Loai;
}

void MAYGIAT::Xuat()
{
    cout << "Cong suat: " << 1;
    cout << endl;
}

class TULANH
{
private:
    int dungTich, soNgan;

public:
    TULANH(){};
    TULANH(int dungTich, int soNgan, int congSuat, int dienAp);
    void Xuat();
};

TULANH::TULANH(int dungTich, int soNgan, int congSuat, int dienAp)
{
    this->dungTich = dungTich;
    this->soNgan = soNgan;
}

void TULANH::Xuat()
{
}

int main()
{
    MAYGIAT a(10, "Ngang", 200, 220);
    a.Xuat();
    TULANH b(4, 2, 120, 220);
    b.Xuat();
}