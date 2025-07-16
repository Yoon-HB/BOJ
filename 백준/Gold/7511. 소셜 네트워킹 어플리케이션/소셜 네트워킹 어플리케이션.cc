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

	int t;
	cin >> t;

	for (int test = 1; test <= t; test++) {

		int n; // 유저 수
		int k; // 관계 수
		cin >> n;
		cin >> k;

		fill(p.begin(), p.begin()+n+1, -1);

		//친구 관계 표시
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			uni(a, b);
		}

		int m;
		cin >> m;

		cout << "Scenario " << test << ":" << "\n";

		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;

			if (find(u) == find(v)) cout << "1" << "\n";
			else cout << "0" << "\n";
		}
        
        cout << "\n"; //출력 형식 주의!!
	}
	return 0;
}