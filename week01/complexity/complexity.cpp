#include <iostream>

using namespace std;

int n, k;
int a[1000500];

void smart() {
    cerr << "Smart started!\n";
    int sum = 0;
    for (int i = 1; i <= k; i++) {
        sum += a[i];
    }
    cout << sum << ' ';
    for (int i = 2; i <= n - k + 1; i++) {
        sum -= a[i-1];
        sum += a[i + k - 1];
//        cout << sum << ' ';
    }
//    cout << "\n";

    cerr << "Smart finished!\n";
}

void stupid() {
    cerr << "Stupid started!\n";
    for (int i = 1; i <= n-k+1; i++) {
        int sum = 0;
        for (int j = i; j <= i + k - 1; j++) {
            sum += a[j];
        }
//        cout << sum << ' ';
    }
//    cout << "\n";
    cerr << "Stupid finished!\n";
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    smart();
    stupid();


    return 0;
}