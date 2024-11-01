#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool vis[502][502];
int board[502][502];

int main() {
	int M, N, K;
	cin >> M >> N >> K;

	//직사각형 칠하기
	for (int t = 0; t < K; t++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		for (int i = a; i < c; i++) {
			for (int j = b; j < d; j++) {
				if (board[j][i] == 0) {
					board[j][i] = 1;
				}
			}
		}
	}
	//보드출력
	/*for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}*/

	vector<int> ans; //영역의 넓이를 담을 동적 배열

	//BFS 탐색
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 1 || vis[i][j]) continue;
			queue<pair<int, int>> Q;

			int area = 0; //해당 영역의 넓이 구하기
			Q.push({ i, j }); //큐에 넣고 시작
			vis[i][j] = 1; //큐에 넣었으니 방문한 칸

			while (!Q.empty()) {
				area++; //면적 크기 증가

				pair<int, int> cur = Q.front();
				Q.pop();

				for (int dir = 0; dir < 4; dir++) { //상하좌우 탐색
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue; //범위를 벗어나는 경우 지나감
					if (board[nx][ny] != 0 || vis[nx][ny]) continue; //방문 했거나 구하는 영역이 아닌 경우 지나감
					Q.push({ nx, ny });
					vis[nx][ny] = 1;
				}
			}
			ans.push_back(area); //원소 삽입
		}
	}

	sort(ans.begin(), ans.end()); //오름차순 정렬

	//답 출력
    cout << ans.size() << "\n";
	for (auto i : ans) {
		cout << i << " ";
	}
	return 0;
}
