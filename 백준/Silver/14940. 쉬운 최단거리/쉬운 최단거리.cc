#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, M;

int dis[1002][1002];
int board[1002][1002];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };


int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			dis[i][j] = -1;

	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				dis[i][j] = 0;
				q.push({ i, j });

			}
			else if (board[i][j] == 0) {
				dis[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
			if (dis[nx][ny] != -1) continue;

			dis[nx][ny] = dis[cur.X][cur.Y] + 1;
			q.push({ nx, ny });
		}
	}
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++) {
			cout << dis[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}