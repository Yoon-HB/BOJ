#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> adj[10001];
bool vis[10001];
vector<int> ans;

void bfs() {
	int max_cnt = 0;

	for (int i = 1; i <= N; i++) {
		int cnt = 0;

		queue<int> q;
		q.push(i);
		vis[i] = true;

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (auto nxt : adj[cur]) {
				if (vis[nxt]) continue;
				q.push(nxt);
				vis[nxt] = true;
				cnt++;
			}
		}
		fill(vis, vis + N+1, 0);

		if (cnt > max_cnt) {
			ans.clear();
			ans.push_back(i);
			max_cnt = cnt;
		}
		else if (cnt == max_cnt) ans.push_back(i);
	}
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
	}
	bfs();

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	return 0;
}