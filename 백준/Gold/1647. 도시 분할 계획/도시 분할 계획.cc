#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> edge[1000002];
vector<int> p(100002, -1);

int N, M;

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return false;

	if (p[u] > p[v]) swap(u, v);
	if (p[u] == p[v]) p[u]--;
	p[v] = u;

	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[i] = { c, a, b };
		
	}

	sort(edge, edge + M);

	int cnt = 0;
	int ans = 0;
	int max_num = 0;

	for (int i = 0; i < M; i++) {
		int cost, a, b;
		tie(cost, a, b) = edge[i];

		if (!is_diff_group(a, b)) continue;

		max_num = max(max_num, cost);
		cnt++;
		ans += cost; //여기서 가장 큰 수 지우면 2개로 분할 되는거 아님?

		if (cnt == N - 1) break;
	}
	cout << ans - max_num;

	return 0;

}