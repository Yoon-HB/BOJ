#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> edge[100005]; //비용, 정점 1, 정점 2
vector<int> p(100005, -1);

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

int uni(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return false;
	if (p[v] < p[u]) swap(u, v);
	if (p[u] == p[v]) p[u]--;
    p[v] = u;
	return true;
}
int main() {

	cin.sync_with_stdio(0);
	cin.tie(0);

	int v, e;

	cin >> v >> e;

	int ans = 0;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[i] = { c, a, b };
	}
	sort(edge, edge + e);
	
	int cnt = 0;

	for (int i = 0; i < e; i++) {
		int cost, a, b;
		tie(cost, a, b) = edge[i];

		if (!uni(a, b)) continue;
		cnt++;
		ans += cost;

		if (cnt == v - 1) break;
	}
	cout << ans;

	return 0;
}