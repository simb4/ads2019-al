#include <iostream>

using namespace std;

int main() {
    int n = 1000000;
    int k = n / 2;
    cout << n << ' ' << k << "\n";
    for (int i = 1; i <= n; i++) {
        cout << rand() % 10 << ' ';
    }
    cout << "\n";

    return 0;
}