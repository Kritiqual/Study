#include <iostream>
#include <stdio.h>
#define MAX 8
using namespace std;
void pause(void) {
    system("echo '\nPress any key to continue...' && ( read x 2> nul; rm nul || pause > nul )");
    return;
}
void cls(void) {
    system("cls||clear");
    return;
}

int a[MAX][MAX] = { 0 };
int X[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int Y[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
int dem = 0;
int n;

void xuat() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%2d ", a[i][j]);
        cout << endl;
    }
    cout << endl;
}

void diChuyen(int x, int y) {
    ++dem;
    a[x][y] = dem;
    for (int i = 0; i < 8; i++) {

        if (dem == n * n) {
            cout << "Cac buoc di la: \n";
            xuat();
        }

        int u = x + X[i];
        int v = y + Y[i];

        if (u >= 0 && u < n && v >= 0 && v < n && a[u][v] == 0)
            diChuyen(u, v);
    }

    --dem;
    a[x][y] = 0;
}
int main() {
    cls();
    cout << "Nhap n: ";
    cin >> n;
    int a, b;
    cout << "Nhap vi tri ban dau.\nx: ";
    cin >> a;
    cout << "y: ";
    cin >> b;
    diChuyen(a, b);

    cout << "Khong tim thay duong di.";
}
