#include <iostream>
using namespace std;

class TamThuc
{
protected:
    int a, b, c;

public:
    TamThuc operator+(TamThuc tt);
    TamThuc operator-(TamThuc tt);
    TamThuc operator--();
    friend istream &operator>>(istream &is, TamThuc &tt);
    friend ostream &operator<<(ostream &os, TamThuc tt);
};

istream &operator>>(istream &is, TamThuc &tt)
{
    is >> tt.a >> tt.b >> tt.c;
    return is;
}

ostream &operator<<(ostream &os, TamThuc tt)
{
    os << tt.a << "x2 + " << tt.b << "x + " << tt.c << " = 0\n";
    return os;
}

TamThuc TamThuc::operator+(TamThuc tt)
{
    TamThuc c;
    c.a = this->a + tt.a;
    c.b = this->b + tt.b;
    c.c = this->c + tt.c;
    return c;
}

TamThuc TamThuc::operator-(TamThuc tt)
{
    TamThuc c;
    c.a = this->a - tt.a;
    c.b = this->b - tt.b;
    c.c = this->c - tt.c;
    return c;
}

TamThuc TamThuc::operator--()
{
    this->a *= -1;
    this->b *= -1;
    this->c *= -1;
    return *this;
}

int main()
{
    TamThuc tt1, tt2, ttsum, ttsubs;
    cin >> tt1;
    --tt1;
    cout << tt1;
    cin >> tt2;
    --tt2;
    cout << tt2;
    ttsum = tt1 + tt2;
    cout << "sum = " << ttsum;
    ttsubs = tt1 - tt2;
    cout << "subs = " << ttsubs;
}
