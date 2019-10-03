#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll w, h, n;	

bool fits(ll a) { // a - side of square
	return floor((double)a / h) * floor((double)a / w) >= n;
}

// problem 
// https://informatics.msk.ru/mod/statements/view3.php?id=1966&chapterid=1923
int main() {
	
	cin >> w >> h >> n;

	// a >= 10^14 => a / 10^9 * a / 10^9 >= 10^9
	ll l = 1, r = (ll)1e14, res = (ll)1e14;
	while (l <= r) {
		ll mid = (l + r) / 2;
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