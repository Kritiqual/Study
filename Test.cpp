#include <iostream>
using namespace std;

class VECTOR
{
private:
    float *p;
    int n;

public:
    VECTOR();
    VECTOR(int, float);
    ~VECTOR();
    friend istream &operator>>(istream &is, VECTOR &x);
    friend ostream &operator<<(ostream &os, VECTOR x);
    VECTOR operator+(VECTOR x);
    VECTOR operator=(VECTOR x);
};

VECTOR::VECTOR()
{
    n = 0;
    p = NULL;
}

VECTOR::VECTOR(int n, float x)
{
    this->n = n;
    p = new float[n];
    for (int i = 0; i < n; i++)
        p[i] = x;
}

VECTOR::~VECTOR()
{
    p = NULL;
    delete p;
}

istream &operator>>(istream &is, VECTOR &x)
{
    is >> x.n;
    x.p = new float[x.n];
    for (int i = 0; i < x.n; i++)
        is >> x.p[i];
    return is;
}

ostream &operator<<(ostream &os, VECTOR x)
{
    for (int i = 0; i < x.n; i++)
        os << x.p[i] << " ";
    return os;
}

VECTOR VECTOR::operator+(VECTOR x)
{
    if (n != x.n) ///So chieu cua 2 vector khac nhau. ( tra ve vector rong)
    {
        VECTOR res;
        return res;
    }
    VECTOR res(n, 0);
    for (int i = 0; i < n; i++)
        res.p[i] = p[i] + x.p[i];
    return res;
}

VECTOR VECTOR::operator=(VECTOR x)
{
    if (n != x.n) ///So chieu cua 2 vector khac nhau. ( tra ve vector thu nhat)
    {
        return *this;
    }
    for (int i = 0; i < n; i++)
        p[i] = x.p[i];
    return *this;
}

int main()
{
    VECTOR test1;
    cout << "test 1 = " << test1 << "(khoi tao khong tham so)" << endl;
    VECTOR test2(5, 3.2);
    cout << "test 2 = " << test2 << endl;
    VECTOR test3(5, 6.3);
    cout << "test 3 = " << test3 << endl;
    cout << "test 2 + test 3 = " << test2 + test3 << endl;
    VECTOR test4(5, 1.0);
    cout << "test 4 = " << test4 << endl;
    test2 = test4;
    cout << "test 2 sau khi gan = test 4: " << test2 << endl;
    return 0;
}