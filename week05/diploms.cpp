#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll w, h, n;	

bool fits(double a) { // a - side of square
	return floor(a / h) * floor(a / w) >= n;
}

// problem 
// https://informatics.msk.ru/mod/statements/view3.php?id=1966&chapterid=1923
int main() {
	
	cin >> w >> h >> n;

	ll l = 1, r = (ll)1e9, res = (ll)1e9;
	while (l <= r) {
		ll mid = (l + r) / 2;
		// cout << "[" << l << ' ' << r << "]\n";
		// cout << mid << ' ' << fits(mid) << ' ' << n << "\n";
		if (fits(mid)) {
			res = mid;
			r = mid - 1; // [l, mid-1]
		}
		else {
			l = mid + 1; // [mid + 1, r]
		}
	}
	cout << res << "\n";

	return 0;
}