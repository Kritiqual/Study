#include <iostream>
#include <cmath>
using namespace std;


int power(int a, int n) {
  int m;
  if (n == 0) return 1;
  if (n % 2 == 0) {
    m = power(a, n / 2);
    return m * m;
  }
  else return a * power(a, n - 1);
}

int S(int i) {
  if (i == 0) return 1;
  return 2 * S(i - 1);
}

int F(int n) {
  if (n <= 2) return 1;
  return F(n - 1) + F(n - 2);
}

int main() {
  int i;
  cout << "Enter i: "; cin >> i;
  cout << "Res: " << F(i) << endl;
}