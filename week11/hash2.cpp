#include <bits/stdc++.h>
using namespace std;
const int N = 40000;
const int p = 257;

string s;
int n;

int main() {

	/*	
		Problem: count the number of diff
		substrings
	*/

	cin >> s;
	n = s.length();

	// was - array of maps,
	// was[len] - map for strings of length len
	map<int, bool> was[n+1]; // 0,1,2,...,n

	// run over each substring [l, r] (1 <= l <= r <= n)
	for (int l = 0; l < n; l++) {
		int hash = s[l];
		for (int r = l; r < n; r++) {
			// [l, r]
			int len = r - l + 1;
			// mark, that string of length 'len'
			// with this value of 'hash' is present
			was[len][hash] = true;

			if (r + 1 < n) // recalculate hash
				hash = hash * p + s[r + 1];
		}
	}
	int ans = 0;
	for (int len = 1; len <= n; len++) {
		// how many different substrings of length len
		ans += was[len].size();
	}
	cout << ans << "\n";


	return 0;
}