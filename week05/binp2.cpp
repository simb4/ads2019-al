#include <iostream>

using namespace std;

int n, k;
int a[100005];

int closest(int x) {
	// a[i] <= x (i - max)
	// a: 1 2 3 4 5
	// x: 0
	if (x <= a[1]) return a[1];
	if (a[n] <= x) return a[n];

	int l = 1, r = n;
	// a[l] <= x <= a[r]
	// a[l]      a[mid]    a[r]
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (a[mid] <= x)
			l = mid;
		else
			r = mid;
	}
	if (x - a[l] <= a[r] - x)
		return a[l];
	return a[r];
}

int main() {

	/*
		problem: closest in array
		https://informatics.msk.ru/mod/statements/view3.php?id=192&chapterid=2#1
	*/

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= k; i++) {
		int x;
		cin >> x;
		cout << closest(x) << "\n";
	}

	return 0;
}