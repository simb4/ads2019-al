#include <bits/stdc++.h>
using namespace std;
const int N = 40000;
const int inf = 1e9;
// #define pb push_back
// #define mp make_pair
// typedef pair<int,int> pii;

int n, m;
vector<pair<int,int> > g[N];
// g[v] - vector, that contain neightbours of vertex v
// e.g. edges that starts from v: (v,u,w)
int S, d[N];
// d[v] - shortest path from vertex S to vertex v

int main() {

	cin >> n >> m >> S;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}

	// step 0
	for (int i = 1; i <= n ; i++)
		d[i] = inf;
	d[S] = 0;
	priority_queue<pair<int,int> > pq;
	pq.push(make_pair(-d[S], S));

	while (!pq.empty()) {
		// step 1
		int v = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();
		cout << "Consider vertex " << v << " with dist=" << dist <<"\n";
		for (int i = 1; i <= n ;i++) {
			cout << "d[" << i << "] = " << d[i] << "\n";
		}

		// step 2
		if (dist != d[v])
			continue;

		// step 3
		for (pair<int,int> e : g[v]) {
			int u = e.first;
			int w = e.second;
			if (d[u] > d[v] + w) {
				d[u] = d[v] + w;
				pq.push(make_pair(-d[u], u));
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << d[i] << " \n"[i == n];


	return 0;
}