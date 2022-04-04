#include <iostream>
using namespace std;
void pause(void) {
    system("echo '\nPress any key to continue...' && ( read x 2> nul; rm nul || pause > nul )");
    return;
}
void cls(void) {
    system("cls||clear");
    return;
}

struct vat {
    float m;
    int c;
};
void nhap(int n, vat v[]) {
    for (int i = 0; i < n; i++) {
        cout << "\nNhap khoi luong va gia tri cho vat thu " << i + 1;
        cout << "\n\tKhoi luong : "; cin >> v[i].m;
        cout << "\tGia tri : "; cin >> v[i].c;
        cin.ignore();
    }
}

void sap_xep(int n, vat v[]) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i; j < n; j++)
            if (v[i].c < v[j].c)
                swap(v[i].c, v[j].c);
}

void balo(float w, int n, vat v[]) {
    float sum_m = 0;
    float sum_c = 0;
    int i = 0;
    while (sum_m + v[i].m <= w) {
        cout << "\nChon vat " << i + 1;
        sum_c += v[i].c;
        sum_m += v[i].m;
        i++;
    }
    cout << "\nTong khoi luong = " << sum_m;
    cout << "\nTong gia tri = " << sum_c;
}

int main() {
    cls();
    float w;
    cout << "Nhap khoi luong toi da cua ba lo : "; cin >> w;
    int n;
    cout << "Nhap so luong do vat : "; cin >> n;

    vat v[n];
    nhap(n, v);
    sap_xep(n, v);
    balo(w, n, v);
}
