// #include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstring>
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

class ELECTRONIC
{
protected:
    float congSuat;
    int dienAp;

public:
    ELECTRONIC();
    ELECTRONIC(float congSuat, int dienAp);
};

ELECTRONIC::ELECTRONIC(float congSuat, int dienAp)
{
    this->congSuat = congSuat;
    this->dienAp = dienAp;
}

class MAYGIAT : public ELECTRONIC
{
private:
    char Loai[30];
    float dungTich;

public:
    MAYGIAT(){};
    MAYGIAT(int dungTich, char Loai[], float congSuat, int dienAp);
    void Xuat();
};

MAYGIAT::MAYGIAT(int dungTich, char Loai[], float congSuat, int dienAp) : ELECTRONIC(congSuat, dienAp)
{
    this->dungTich = dungTich;
    strcpy(this->Loai, Loai);
}

void MAYGIAT::Xuat()
{
    
    cls();
    cout << "=== MAY GIAT ===" << endl
         << "Dung tich: " << dungTich << endl
         << "Loai     : " << Loai << endl
         << "Cong suat: " << congSuat << endl
         << "Dien ap  : " << dienAp << endl;
}

class TULANH : public ELECTRONIC
{
private:
    int soNgan;
    float dungTich;

public:
    TULANH();
    TULANH(int soNgan, float dungTich, float congSuat, int dienAp);
    void Xuat();
};

TULANH::TULANH(int soNgan, float dungTich, float congSuat, int dienAp) : ELECTRONIC(congSuat, dienAp)
{
    this->soNgan = soNgan;
    this->dungTich = dungTich;
}

void TULANH::Xuat()
{
    cout << "\n=== TU LANH ===" << endl
         << "Dung tich: " << dungTich << endl
         << "So ngan  : " << soNgan << endl
         << "Cong suat: " << congSuat << endl
         << "Dien ap  : " << dienAp << endl;
}

int main()
{
    MAYGIAT mg(20, (char *)"Mitsubishi", 300, 220);
    mg.Xuat();

    TULANH tl(10, 20, 420, 220);
    tl.Xuat();
}