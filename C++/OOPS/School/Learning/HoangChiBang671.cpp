// #include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>
#include <cmath>
#include <fstream>
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

class DIEM
{
private:
    float x, y, z;

public:
    DIEM();
    DIEM(float x, float y, float z);
    float operator!();
    DIEM operator+(DIEM N);
    bool operator-(DIEM N);
    friend istream &operator>>(istream &is, DIEM &M);
    friend ostream &operator<<(ostream &os, DIEM M);
};

DIEM::DIEM()
{
    x = 0;
    y = 0;
    z = 0;
}

DIEM::DIEM(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

float DIEM::operator!()
{
    return sqrt(sqrt(x * x + y * y) + z * z);
}

DIEM DIEM::operator+(DIEM N)
{
    DIEM res;
    res.x = x + N.x;
    res.y = y + N.y;
    res.z = z + N.z;
    return res;
}

bool DIEM::operator-(DIEM N)
{
    if (x == N.x && y == N.y && z == N.z)
        return true;
    return false;
}

istream &operator>>(istream &is, DIEM &M)
{
    cout << "Nhap toa do: ";
    is >> M.x >> M.y >> M.z;
    return is;
}

ostream &operator<<(ostream &os, DIEM M)
{
    os << "(" << M.x << "; " << M.y << "; " << M.z << ")";
    return os;
}

int main()
{
    cls();
    DIEM M, N;
    cin >> M >> N;
    cout << M << " >> " << !M << endl
         << N << " >> " << !N << endl
         << M << " + " << N << " = " << M + N << endl;

    ofstream f("./DIEM.txt", ios:app);
    // ofstream f(".\\DIEM.txt", ios::app);
    f << M << " >> " << !M << endl
      << N << " >> " << !N << endl
      << M << " + " << N << " = " << M + N << endl;

    cout << "Hai diem" << ((M - N) ? " " : " khong ") << "trung nhau" << endl;
}