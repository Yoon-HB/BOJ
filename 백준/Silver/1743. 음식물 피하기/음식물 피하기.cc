#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int board[102][102];
int vis[102][102];

int main() {
	int N, M, K;

	cin >> N >> M >> K;


	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		board[x][y] = 1;
	}

	queue<pair<int, int>> q;
	int answer = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int cnt = 0;

			if (vis[i][j] == 0 && board[i][j] == 1) {
				q.push({ i, j });
				vis[i][j] = 1;
				cnt++;
			}
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
					if (vis[nx][ny] || board[nx][ny] == 0) continue;
					q.push({ nx, ny });
					cnt++;

					vis[nx][ny] = 1;

				}
			}
			answer = max(answer, cnt);
		}
	}
	cout << answer;
	return 0;
}