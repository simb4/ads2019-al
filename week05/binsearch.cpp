#include <iostream>

using namespace std;

int n, k;
int a[100005];


bool binsearch2(int x) {
	int l = 1, r = n, res = 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (x <= a[mid]) {// [l, mid]
			res = mid;
			r = mid - 1;
		} else
			l = mid + 1;
	}
	return a[res] == x;
}

bool binsearch(int x) {
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r) / 2;
		if (x <= a[mid]) // [l, mid]
			r = mid;
		else
			l = mid + 1;
	}
	return a[l] == x;
}

int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= k; i++) {
		int x;
		cin >> x;
		if (binsearch(x)) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

}