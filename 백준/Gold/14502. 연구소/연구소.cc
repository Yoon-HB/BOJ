#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int board[10][10];
int dx[4] = { 1, 0 , -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N, M;
int ans;

void virus() {
    int temp[10][10];
    bool vis[10][10] = {};  // 방문 여부
    queue<pair<int, int>> q;

    //복사
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            temp[i][j] = board[i][j];

    // 1. 바이러스가 있는 칸을 큐에 넣고 시작
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (temp[i][j] == 2) {
                q.push({ i, j });
                vis[i][j] = true;
            }
        }
    }

    // 2. BFS로 전염 시작
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (vis[nx][ny] || temp[nx][ny] != 0) continue;
            vis[nx][ny] = true;
            temp[nx][ny] = 2; // 바이러스 감염
            q.push({ nx, ny });
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (temp[i][j] == 0) cnt++;

    ans = max(ans, cnt); // 최대값 갱신
}

void wall(int cnt) {
	if (cnt == 3) {
        virus();
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0) {
				board[i][j] = 1; // 벽 세우기
				wall(cnt + 1); // 다음 벽
				board[i][j] = 0; // 백트래킹 중요!!!!!
			}
		}
	}
}



int main() {
	
    cin.sync_with_stdio(0);
    cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

    wall(0);
    cout << ans;
}