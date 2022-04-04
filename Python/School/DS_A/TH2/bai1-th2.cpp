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

void sapxep(int a[10000], int n) {
    int t;
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (a[i] < a[j])
                swap(a[i], a[j]);
}

int main() {
    cls();
    int n, p = 0, s, a[10000];
    cout << "nhap n: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "nhap a[" << i << "]: ";
        cin >> a[i];
    }
    cout << "nhap s: ";
    cin >> s;

    sapxep(a, n);
    for (int i = 0; i < n; ++i)
        if (p < s)
            p += a[i];
        else {
            cout << "Can it nhat " << i << " so";
            break;
        }

    // p = 0;
    // int i = 0;
    // while (p < s) {
    //     p += a[i];
    //     i++;
    //     if (p > s) {
    //         cout << "Can it nhat " << i << " so";
    //         break;
    //     }
    // }
}
