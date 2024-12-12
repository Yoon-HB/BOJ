#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
bool vis[1001];
bool vis_dfs[1001];

//BFS로 탐색한 결과 -> queue
void bfs(int cur) {
	queue<int> q;
	q.push(cur);
	vis[cur] = true;
	while (!q.empty()) {
		cout << q.front() << " ";
		int cur = q.front();
		q.pop();
		for (auto nxt : adj[cur]) {
			if (vis[nxt]) continue;
			q.push(nxt);
			vis[nxt] = true;
		}
	}
}

//DFS로 탐색한 결과 -> 재귀
void dfs(int cur) {
	cout << cur << " ";
	vis_dfs[cur] = true;
	for (auto nxt : adj[cur]) {
		if (vis_dfs[nxt]) continue;
		dfs(nxt);
	}
}
//DFS로 탐색한 결과 -> stack
void dfs2(int cur) {
	stack<int> st;
	st.push(cur);
	vis_dfs[cur] = true;
	while (!st.empty()) {
		cout << st.top() << " ";
		int cur = st.top();
		st.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			//주의!!! main 함수에서 정렬되어 들어오기 때문에 stack 구조의 특성상 작은 것이 뒤로 가야함
			int nxt = adj[cur][adj[cur].size() - 1 - i];
			if (vis_dfs[nxt]) continue;
			st.push(nxt);
			vis_dfs[nxt] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, V;
	cin >> N >> M >> V;

	//간선은 양방향이다.
	for (int i = 0; i < M; i++) {
		int  x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	//방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문
	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	dfs(V);
	cout << "\n";
	bfs(V);

	return 0;
}