#include <iostream>

using namespace std;

void out_array(int *a, int n) {
	for (int i = 1; i <= n; i++) {
		printf("%d%c", a[i], " \n"[i == n]);
	}
}

int heapify_down(int *a, int n, int v) {
	while (v <= n) {
		int l = 2 * v; // left son
		int r = 2 * v + 1; // right son
		int s = v; // max among a[v],a[l],a[r]

		/* let's find max */
		if (l <= n && a[l] > a[s])
			s = l;
		if (r <= n && a[r] > a[s])
			s = r;

		// if v is max, then everything is ok
		if (s == v) break;
		// go down to vertex s
		swap(a[v], a[s]);
		v = s;
	}
	return v;
}


// these variables are lower than functions,
// so functions can't see them
int a[100005], n;

int main() {

	/*
		problem from
		https://informatics.msk.ru/mod/statements/view3.php?id=1234&chapterid=1165#1
	*/

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int pos, x;
		scanf("%d %d", &pos, &x);
		a[pos] -= x;
		int newPos = heapify_down(a, n, pos);
		printf("%d\n", newPos);
	}
	out_array(a, n);



	return 0;
}
