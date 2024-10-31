#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[102][102];


int N;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };


int cnt = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	int min_num = 100;
	int max_num = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			min_num = min(min_num, board[i][j]); //높이 최소값
			max_num = max(max_num, board[i][j]); //높이 최대값
		}
	}

	int answer = 0;
	

	for (int k = min_num; k <= max_num; k++) {
		bool vis[102][102] = { 0, }; //방문 표시 배열 초기화
		int cnt = 0; //높이가 k일때 안전한 영역 개수

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				//해당 칸이 잠기는 곳이거나 이미 방문했을 경우 넘어감
				if (board[i][j] < k || vis[i][j]) continue; 
				cnt++;// 영역의 개수 증가

				queue<pair<int, int>> Q;
				vis[i][j] = 1; //(i, j)로 BFS를 시작하기 위한 준비
				Q.push({ i, j });

				while (!Q.empty()) {
					pair<int, int> cur = Q.front();
					Q.pop();

					for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴볼 것이다.
						// nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						// 범위 밖일 경우 넘어감
						if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
						// 이미 방문한 칸이거나 잠기는 곳인 경우
						if (vis[nx][ny] || board[nx][ny] < k) continue;
						vis[nx][ny] = 1;  // (nx, ny)를 방문했다고 명시
						Q.push({ nx, ny });
					}
				}
			}
		}
		answer = max(answer, cnt); //영역 최대값 구하기
	}
	cout << answer;
	return 0;
}