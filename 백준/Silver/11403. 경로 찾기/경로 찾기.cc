#include <bits/stdc++.h>
using namespace std;

int arr[102][102];
int ans[102][102];
vector<int> adj[102];
bool vis[102];

void dfs(int cur) {

	for (auto nxt : adj[cur]) {
		if (vis[nxt]) continue;
		else {
			vis[nxt] = 1;
			dfs(nxt);
		}
	}
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 1) adj[i].push_back(j);

		}
	}
    
	for (int i = 0; i < N; i++) {
		dfs(i);

		for (int j = 0; j < N; j++) {
			cout << vis[j] << " ";
		}
		cout << "\n";

		fill(vis, vis +N+1, 0);
	}

}