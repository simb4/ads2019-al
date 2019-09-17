#include <iostream>
#include <vector>

using namespace std;

int n;
bool was[1005];

int main() {

    cin >> n;
    vector< pair<int, int> > fact;

    int x = n;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            // this number must be prime
            int cnt = 0;
            while (x % i == 0)
                x /= i, cnt++;
            fact.push_back( make_pair(i, cnt) );
        }
    }
    if (x > 1) {
        fact.push_back( make_pair(x, 1) );
    }
    cout << n << " = ";
    for (int i = 0; i < (int)fact.size(); i++) {
        if (i > 0)
            cout << " * ";
        cout << fact[i].first << "^" << fact[i].second;
    }
    cout << "\n";

    return 0;
}