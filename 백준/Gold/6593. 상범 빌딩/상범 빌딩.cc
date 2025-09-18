#include<bits/stdc++.h>
using namespace std;

//tuple 접근방식!
#define X get<2>
#define Y get<1>
#define Z get<0>

int dx[6] = { 1, 0, -1, 0, 0, 0 }; //위, 아래 확인 추가
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

char build [32][32][32];
bool vis[32][32][32];
int cnt[32][32][32];


int main() {

	cin.sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		
		int L, R, C;
		cin >> L >> R >> C;

		if (L == 0 && R == 0 && C == 0) break;

		//배열 초기화
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					vis[i][j][k] = false;
					cnt[i][j][k] = 0;
				}
			}
		}

		int a, b, c = 0;

		queue<tuple<int, int, int>> q; //tuple 큐

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					cin >> build[i][j][k];
					if (build[i][j][k] == 'S') { //시작지점일 경우 큐에 추가하고 방문 표시. 시간도 0
						q.push({ i, j, k });
						vis[i][j][k] = true;
						cnt[i][j][k] = 0;
					}
					else if (build[i][j][k] == 'E') {
						tie(a, b, c) = { i, j, k }; //탈출지점 기억?

					}
				}
			}
		}
		bool flag = false;

		while (!q.empty()) {
			if (flag) break;

			auto cur = q.front();
			q.pop();
			int x = X(cur), y = Y(cur), z = Z(cur);

			for (int dir = 0; dir < 6; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				int nz = z + dz[dir];

				if (nx < 0 || nx >= C || ny < 0 || ny >= R || nz < 0 || nz >= L) continue;

				if (build[nz][ny][nx] == 'E') { //탈줄 지점일 경우 
					cnt[nz][ny][nx] = cnt[z][y][x] + 1;
					flag = true;
					break;
				}

				if (vis[nz][ny][nx] || build[nz][ny][nx] == '#') continue;
				cnt[nz][ny][nx] = cnt[z][y][x] + 1;
				q.push({ nz, ny, nx });
				vis[nz][ny][nx] = true;
			}
		}
		if (flag) cout << "Escaped in " << cnt[a][b][c] << " minute(s).\n";
		else cout << "Trapped!\n";
	}
	
	return 0;
}