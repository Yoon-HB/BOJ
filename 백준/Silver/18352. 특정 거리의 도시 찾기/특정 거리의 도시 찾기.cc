#include <bits/stdc++.h>
using namespace std;

vector<int> adj[300005];
int dis[300005];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, K, X; //도시의 개수 N, 도로의 개수 M, 거리 정보 K, 출발 도시의 번호 X
	cin >> N >> M >> K >> X;

	fill(dis, dis + N + 1, -1);

	while (M--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}

	queue<int> q;
	q.push(X);
	dis[X] = 0; //!!!!!!!!!!!!!중요!!!!!!!!!!!!!!!

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto nxt : adj[cur]) {
			if (dis[nxt] != -1) continue;

			dis[nxt] = dis[cur] + 1;
			q.push(nxt);
		}
	}
	vector<int> ans;


	for (int i = 1; i <= N; i++) {
		if (dis[i] == K) ans.push_back(i);
	}

	sort(ans.begin(), ans.end());

	if (!ans.empty()) {
		for (int i : ans) {
			cout << i << "\n";
		}
	}
	else cout << -1;

	return 0;
}