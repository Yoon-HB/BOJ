#include <bits/stdc++.h>
using namespace std;

vector<int> adj[102];
bool vis[102];

int a, b;
int cnt;

int dfs(int cur, int cnt) {
	vis[cur] = true;
	if (cur == b) return cnt;
	
	for (auto nxt : adj[cur]) {
		
		if (vis[nxt]) continue;
		
		int res = dfs(nxt, cnt+1);
		if (res != -1) return res;
	}

	return -1;
}
int main() {
	int n;
	cin >> n;

	cin >> a >> b;

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	int ans = dfs(a, 0);
	cout << ans;

	return 0;
}