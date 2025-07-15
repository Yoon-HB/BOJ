#include<bits/stdc++.h>
using namespace std;
vector<int> p(1000001, -1);

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool uni(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return false;
	if (p[v] < p[u]) swap(u, v);
	if (p[u] == p[v])
		p[u]--;
	p[v] = u;
	return true;
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	//0 a b 는 합집합 연산 / 1 a b 는 같은 집합인지 확인하는 연산
	for (int i = 0; i < m; i++) {
		int k, a, b;
		cin >> k >> a >> b;

		if (k == 0) {
			uni(a, b);
		}
		else {
			if (find(a) == find(b)) cout << "YES" << "\n";
			else cout << "NO" << "\n";
		}
	}
	return 0;
}