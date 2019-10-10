#include <iostream>

using namespace std;

int n, k;
int a[100005];

int heapify_up(int v) {
	while (v > 1 && a[v] > a[v / 2]) {
		swap(a[v], a[v/2]);
		v /= 2;
	}
	return v;
}

void heapify_down(int v) {
	while (v <= n) {
		int l = 2 * v; // left son
		int r = 2 * v + 1; // right son
		int s = v; // max among a[v],a[l],a[r]

		/* let's find max */
		if (l <= n && a[l] > a[s])
			l = s;
		if (r <= n && a[r] > a[s])
			r = s;

		// if v is max, then everything is ok
		if (s == v)
			return;
		// go down to vertex s
		swap(a[v], a[s]);
		v = s;
	}
}

void add(int x) {
	// add to the end
	n++;
	a[n] = x;
	// propogate (heapify) upwards
	heapify_up(n);
}

int top() {
	// max element is on top
	return a[1];
}

int remove_top() { // a.k.a. pop()
	// swap max with last element
	swap(a[1], a[n]);
	// delete last element (delete max)
	n--;
	// propogate top element downwards
	heapify_down(1);
}

int main() {

	/*
		problem from
		https://informatics.msk.ru/mod/statements/view3.php?id=1234&chapterid=1164#1
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
		a[pos] += x;
		int newPos = heapify_up(pos);
		printf("%d\n", newPos);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d%c", a[i], " \n"[i == n]);
	}



	return 0;
}