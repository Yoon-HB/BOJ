#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int N, M;

int room[52][52];
int vis[52][52];

//북, 동 , 남 , 서
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int cnt = 0;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int r, c, d;

	cin >> N >> M;
	cin >> r >> c >> d; //0 - 북, 1 - 동, 2 - 남, 3 - 서

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> room[i][j]; // 0 -청소 X / 1 - 벽
		}
	}

	//반시계 방향으로 회전 ->하면 좌표는 
	//북(0) -> 서(3)( x--, y) / 동(1) -> 북(0)(x, y--) / 남(2) -> 동(1) (x++, y) / 서(3) -> 남(2) (x, y++)

	while (1) {
		if (room[r][c] == 0) {
			room[r][c] = 2; // 청소함
			cnt++;
		}
		bool check = false;

		for (int dir = 0; dir < 4; dir++) {
			int nx = r + dx[dir];
			int ny = c + dy[dir];

			if (nx >= 0 && nx <N && ny >= 0 && ny < M) {
				if (room[nx][ny] == 0) {
					check = true;
					break;
				}
			}
		}
		if (check) {
			//반시계 회전 - 방향 갱신
			d = (d + 3) % 4;

			int nx = r + dx[d];
			int ny = c + dy[d];

			if (room[nx][ny] == 0) {
				r = nx;
				c = ny;
			}
		}
		else {
			int back = (d + 2) % 4;

			//후진했을 때
			int nx = r + dx[back];
			int ny = c + dy[back];
	
			if (room[nx][ny] == 1) {
				break;
			}
			else {
				r = nx;
				c = ny;
			}
		}
	}
	cout << cnt;

	return 0;
}