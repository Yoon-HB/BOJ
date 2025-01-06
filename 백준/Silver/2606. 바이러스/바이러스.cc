#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
bool vis[101];
int cnt = 0;

void bfs() {
	queue<int> q;
	q.push(1);
	vis[1] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto nxt : adj[cur]) {
			if (vis[nxt]) continue;
			q.push(nxt);
			cnt++;
			vis[nxt] = true;
		}
		
	}
}
int main() {
	int n;
	cin >> n; //컴퓨터 수

	int k;
	cin >> k;


	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);

	}
	bfs();

	cout << cnt;

	return 0;
}