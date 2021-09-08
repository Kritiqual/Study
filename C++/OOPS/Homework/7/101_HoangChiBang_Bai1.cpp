#include <iostream>
using namespace std;

class SoPhuc
{
protected:
    int a, b;

public:
    SoPhuc(){};
    SoPhuc(int a, int b);
    void Xuat();
    SoPhuc operator+(SoPhuc x);
    SoPhuc operator-(SoPhuc x);
};

SoPhuc::SoPhuc(int a, int b)
{
    this->a = a;
    this->b = b;
}

void SoPhuc::Xuat()
{
    cout << endl;
    cout << a << " + i * " << b;
}

SoPhuc SoPhuc::operator+(SoPhuc x)
{
    SoPhuc c;
    c.a = this->a + x.a;
    c.b = this->a + x.b;
    return c;
}

SoPhuc SoPhuc::operator-(SoPhuc x)
{
    SoPhuc c;
    c.a = this->a - x.a;
    c.b = this->a - x.b;
    return c;
}

int main()
{
    SoPhuc SP1(1, 2), SP2(2, 4), SP3, SP4;
    SP3 = SP1 + SP2;
    SP3.Xuat();
    SP4 = SP1 - SP2;
    SP4.Xuat();
}
