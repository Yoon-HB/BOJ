#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = { 1, 0 ,-1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int time1[1002][1002];
int time2[1002][1002];


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int w, h;
		cin >> w >> h;
		
		int answer = -1;

		string board[1002] = {""};

		for (int i = 0; i < h; i++) {
			cin >> board[i];
		}

		for (int i = 0; i < h; i++) {
			fill(time1[i], time1[i] + w, -1);
			fill(time2[i], time2[i] + w, -1);

		}
		queue<pair<int, int>> q1; //불 bfs
		queue<pair<int, int>> q2; //상근 bfs

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (board[i][j] == '*') {
					q1.push({ i, j });
					time1[i][j] = 0;
				}
				if (board[i][j] == '@') {
					q2.push({ i, j });
					time2[i][j] = 0;
				}
			}
		}
		//먼저 불을 bfs 돌려서 해당 지점까지 불이 번지는지 시간 측정
		while (!q1.empty())
		{
			auto cur = q1.front();
			q1.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (time1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
				time1[nx][ny] = time1[cur.X][cur.Y] + 1;
				q1.push({ nx,ny });
			}
		}

		//상근이에 대한 BFS
		while (!q2.empty()) {
			auto cur = q2.front();
			q2.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
					// 범위를 벗어났다는 것은 탈출에 성공했다는 의미. 큐에 거리 순으로 들어가므로 최초에 탈출한 시간을 출력하면 됨.
					answer = time2[cur.X][cur.Y] + 1;
					break;
				}

				if (time2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
				
				if (time1[nx][ny] != -1 && time1[nx][ny] <= time2[cur.X][cur.Y] + 1) continue; // 불의 전파 시간을 조건에 추가
				
				time2[nx][ny] = time2[cur.X][cur.Y] + 1;
				q2.push({ nx,ny });
			}
			if (answer != -1) break;

		}
		if (answer == -1) cout << "IMPOSSIBLE\n";
		else cout << answer << "\n";
	}
	return 0;
}