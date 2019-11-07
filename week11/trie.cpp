#include <iostream>
using namespace std;
const int N = 1000;

#define IS_DEBUG true
#define DEBUG if (IS_DEBUG) cout


int vn = 1, to[26][N], cnt[N];
// initially array to[][] is filled with zeros
// "to[a][v] = u" means from v to u
// there is an edge with letter 'a'
// e.g. if:
//    v letter a
// to[a][1] = 2 - son of 1 by letter a
//       ^ vertex 1
// to[b][1] = 3 - son of 1 by letter b
// to[b][2] = 4 - son of 2 by letter b
// to[c][1] = 0 - means no son of 1 by letter c
//    (1)
//    / \
//  a/   \b
//  /     \
//(2)     (3)
// \
//  \b
//   \
//   (4)

void out_trie(int v = 1, int tab = 2, int h=0) {
	if (!IS_DEBUG) return;
	// for (int i=0;i<tab;i++) cout << ' ';
	if (v == 1)
		DEBUG << "@ " << v << "\n";
	for (int i = 0; i < 26; i++) {
		int u = to[i][v];
		if (u != 0) {
			for (int j=0;j<tab;j++) DEBUG << ' ';

			if  (u == h) DEBUG << '!';
			DEBUG << (char)(i + 'a') << ' ' << u << "\n";
			out_trie(u, tab + 2, h);
		}
	}
}

int newVertex() {
	// give new id to vertex
	// vn++;
	// return vn;
	return ++vn;
}

void trie_add(string s) {
	int v = 1; // root
	int n = s.length();
	for (int i = 0; i < n; i++) {
		// take next char
		char ch = s[i] - 'a';

		// no transition
		if (to[ch][v] == 0) { // no vertex by letter ch
			to[ch][v] = newVertex();
		}
		v = to[ch][v]; // transition to v
		
		// this is just debug output, run it,
		// and will see the trie.
		out_trie(1, 2, v);
		DEBUG << "------\n";
	}
}

int main() {

	/*	
		Problem: count the number of diff
		substrings
	*/

	string s;
	cin >> s;
	int n = s.length();
	for (int i = 0; i < n; i++) {
		// take suffix[i] = s[i,n)
		string suff = s.substr(i);
		// adding to trie
		DEBUG << "Adding: " << suff << "\n";
		trie_add(suff);
	}
	cout << vn - 1 << "\n";



	return 0;
}