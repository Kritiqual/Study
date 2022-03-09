#include <iostream>
using namespace std;

void cls(void)
{
    system("cls||clear");
    return;
}

void pause(void)
{
    system("echo Press anything to continue... && ( read x 2> nul; rm nul || pause > nul )");
    return;
}

int main() 
{
    int n;
    do 
    {    
        cls();
        cout << "Nhap n = ";
        cin >> n;
        pause();
    }
    while (n<10 && n>0);

}