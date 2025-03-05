#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

char board[101][101];
bool vis[101][101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int cnt = 0;
int N;

void bfs(int i, int j) {

	queue<pair<int, int>> Q;
	vis[i][j] = 1;
	Q.push({ i,j }); //시작점

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (vis[nx][ny] == 1 || board[i][j] != board[nx][ny]) continue;
			vis[nx][ny] = 1;
			Q.push({ nx,ny });
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!vis[i][j]) {
				cnt++;
				bfs(i, j);
			}
		}
	}
	int ans1 = cnt;

	cnt = 0; // 초기화

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 'G') {
				board[i][j] = 'R';
			}
		}
	}

	for (int i = 0; i < N; i++) { // 방문배열 초기화
		fill(vis[i], vis[i] + N, 0);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!vis[i][j]) {
				cnt++;
				bfs(i, j);
			}
		}
	}
	int ans2 = cnt;

	cout << ans1 << " " << ans2;

	return 0;
}