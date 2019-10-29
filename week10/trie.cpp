#include <iostream>

using namespace std;
const int N = 1000;

int vn = 1, to[26][N], cnt[N];
// "to[a][v] = u" means from v to u
// there is an edge with letter 'x'

int newVertex() { return ++vn; }

void out_trie(int v = 1, int tab = 0, int h=0) {
	if (cnt[v] == 0) return;
	// for (int i=0;i<tab;i++) cout << ' ';
	// // cout << v << "\n";
	for (int i = 0; i < 26; i++) {
		int u = to[i][v];
		if (u != 0) {
			for (int j=0;j<tab;j++) cout << ' ';

			cout << (char)(i + 'a') << ' ';
			if  (u == h) cout << '!';
			cout << u << "\n";
			out_trie(u, tab + 2, h);
		}
	}
}

void trie_add(string s) {
	int v = 1;
	int n = s.length();
	for (int i = 0; i < n; i++) {
		char ch = s[i] - 'a';
		if (to[ch][v] == 0) { // no transition
			to[ch][v] = newVertex();
		}
		cnt[v]++;
		v = to[ch][v]; // transition to v
		out_trie(1, 0, v);
		cout << "------\n";
	}
}

int get_trie(string t) {
	int v = 1;
	int n = t.length();
	for (int i = 0; i < n; i++) {
		char ch = t[i] - 'a';
		if (to[ch][v] == 0)
			return 0;
		v = to[ch][v];
	}
	return cnt[v];
}

int main() {

	/*
		problem from
		https://informatics.msk.ru/mod/statements/view3.php?id=1234&chapterid=1164#1
	*/

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		trie_add(s);
		cout << "==============\n";
	}
	int m;
	cin >> m;
	while (m--) {
		string t;
		cin >> t;
		cout << get_trie(t) << "\n";
	}



	return 0;
}