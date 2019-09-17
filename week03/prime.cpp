#include <iostream>

using namespace std;

bool isPrime(int x) {
    if (x == 1) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {

    int p;
    cin >> p;
    cout << (isPrime(p) ? "Yes" : "No") << "\n";

    return 0;
}