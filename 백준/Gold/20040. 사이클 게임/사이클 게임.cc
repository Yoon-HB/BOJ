#include <bits/stdc++.h>
using namespace std;

vector<int> p(500002, -1);

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

int uni(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return false; //루트가 같다면 이미 같은 집합 → 사이클 발생

	if (p[u] > p[v]) swap(u, v);
	if (p[u] == p[v]) p[u]--;
	p[v] = u;

	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int ans = 0;

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;

		if (uni(a, b) == false) {
			ans = i;
			break;
		}
		
	}
	cout << ans;
	return 0;
}