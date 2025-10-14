#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> adj[20002];
int dis[20002];

void bfs(int n) {
	queue<int> q;
	dis[n] = 0;
	q.push(n);

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (auto nxt : adj[cur]) {
			if (dis[nxt] != -1) continue;
			dis[nxt] = dis[cur] + 1;
			q.push(nxt);
		}
	}
	
}
int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	fill(dis, dis + N+1, -1);

	bfs(1);

	priority_queue<pair<int, int>> pq;

	vector<int> ans;
	
	for (int i = 2; i <= N; i++) {
		//cout << i << " : " << dis[i] << "\n";
		pq.push({ dis[i], i });
	}

	auto res = pq.top(); //거리가 가장 먼 것 
	pq.pop();

	int cnt = 1;
	int a = res.second;

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();

		if (cur.first == res.first) {
			cnt++;
			a = cur.second;
			res = cur;
		}
		else break;
	}

	cout << a << " " << res.first << " " << cnt;

	return 0;
}
//숨어야 하는 헛간 번호(여러개면 가장 작은 헛간 번호), 헛간까지의 거리, 헛간과 같은 거리를 갖는 헛간의 개수