#include <iostream>
using namespace std;
const int N = 1000;

#define IS_DEBUG true
#define DEBUG if (IS_DEBUG) cout


int vn = 1, to[26][N], cnt[N];
// "to[a][v] = u" means from v to u
// there is an edge with letter 'a'
// e.g. if:
// to[a][1] = 2 - son of 1 by letter a
// to[b][1] = 3 - son of 1 by letter b
// to[b][2] = 4 - son of 2 by letter b
//     1
//    / \
//  a/   \b
//  /     \
// 2       3
// \
//  \b
//   \
//    4

int newVertex() {
	// give new id to vertex
	return ++vn;
}

void out_trie(int v = 1, int tab = 2, int h=0) {
	if (!IS_DEBUG) return;
	if (cnt[v] == 0) return;
	// for (int i=0;i<tab;i++) cout << ' ';
	if (v == 1)
		DEBUG << "@ " << v << "\n";
	for (int i = 0; i < 26; i++) {
		int u = to[i][v];
		if (u != 0) {
			for (int j=0;j<tab;j++) DEBUG << ' ';

			if  (u == h) DEBUG << '!';
			DEBUG << (char)(i + 'a') << ' ';
			DEBUG << u << " cnt="<< cnt[u] << "\n";
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
		cnt[v]++; // counter of pluses (if I passed the vertex with some string)
		v = to[ch][v]; // transition to v
		out_trie(1, 2, v);
		DEBUG << "------\n";
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
		out_trie(1, 2, v);
		DEBUG << "----------------------\n";
	}
	return cnt[v];
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		trie_add(s);
		DEBUG << "==============\n";
	}
	int m;
	cin >> m;
	while (m--) {
		string t;
		cin >> t;
		DEBUG << "CALCULATE ANSWER FOR STRING: " << t << "\n";
		cout << get_trie(t) << "\n";
		DEBUG << "=============================\n";
	}



	return 0;
}