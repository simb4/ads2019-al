#include <bits/stdc++.h>
using namespace std;
const int N = 40000;
const int p = 257;

string s;
int h[N], pw[N], n, ans;

int get_hash(int l, int r) {
	if (l == 0) return h[r];
	return h[r] - h[l-1] * pw[r-l+1];
}

int main() {

	/*	
		Problem: count the number of diff
		substrings
	*/

	cin >> s;
	n = s.length();
	pw[0] = 1;
	h[0] = s[0];
	for (int i = 1; i < n; i++) {
		pw[i] = pw[i-1] * p;
		h[i] = h[i-1] * p + s[i];
	}

	map<int, bool> has_hash;
	for (int len = 1; len <= n; len++) {
		has_hash.clear();
		for (int i = 0; i + len <= n; i++) {
			// [i, i + len)
			int H = get_hash(i, i + len - 1);
			has_hash[H] = true;
		}
		ans += (int)has_hash.size();
	}

	cout << ans << "\n";


	return 0;
}