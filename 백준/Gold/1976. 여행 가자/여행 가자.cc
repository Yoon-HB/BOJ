#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> p(202, -1);
vector<int> adj[202];

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool uni(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return false;

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

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++) {
			int n;
			cin >> n;

			if (n == 1) {
				uni(i, j);
			}
		}
	}

	int vis;
	cin >> vis;

	string answer;

	for (int i = 0; i < M - 1; i++) {
		int city;
		cin >> city;

		int u = find(vis);
		int v = find(city);

		if (u == v) {
			answer = "YES";
		}
		else {
			answer = "NO";
			break;
		}
	}

	cout << answer;
	return 0;
}