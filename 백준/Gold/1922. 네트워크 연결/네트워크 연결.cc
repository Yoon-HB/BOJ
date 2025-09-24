#include <bits/stdc++.h>
using namespace std;

int N, M;
tuple<int, int, int> edge[100002]; //간선 기준,,,
vector<int> p(1002, -1);

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return 0;
	if (p[u] > p[v]) swap(u, v);

	if (p[u] == p[v]) p[u]--;
	p[v] = u;

	return true;

}

int main() {

	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[i] = { c, a, b };
	}
	sort(edge, edge + M);

	int cnt = 0;
	int ans= 0; 

	for (int i = 0; i < M; i++) {
		int cost, a, b;
		tie(cost, a, b) = edge[i];
		if (!is_diff_group(a, b)) continue;
		cnt++;
		ans += cost;

		if (cnt == N - 1) break;
	}

	cout << ans;
	return 0;

}