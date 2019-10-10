#include <iostream>

using namespace std;

void heapify_down(int *a, int n, int v) {
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
		if (s == v) return;
		// go down to vertex s
		swap(a[v], a[s]);
		v = s;
	}
}

int remove_top(int *a, int &n) { // a.k.a. pop()
	// swap max with last element
	swap(a[1], a[n]);
	// delete last element (delete max)
	n--;
	// propogate top element downwards
	heapify_down(a, n, 1);
}

void out_array(int *a, int n) {
	for (int i = 1; i <= n; i++) {
		printf("%d%c", a[i], " \n"[i == n]);
	}
}

void heap_sort(int *a, int n) { // sort an array [1..n]
	for (int i = n/2; i > 0; i--) {
		heapify_down(a, n, i);
	}
	// puts("build heap");
	out_array(a, n);
	// n  - size of inital array, that we descrease
	// 		until we removed all maxes
	while (n > 1) {
		remove_top(a, n);
		// printf("step %d:\n", n);
		out_array(a, n);
	}
}


// these variables are lower than functions,
// so functions can't see them
int a[100005], n;

int main() {

	/*
		problem from
		https://informatics.msk.ru/mod/statements/view3.php?id=1234&chapterid=1171#1
	*/

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	heap_sort(a, n);
	// puts("sorted array:");
	out_array(a, n);



	return 0;
}
