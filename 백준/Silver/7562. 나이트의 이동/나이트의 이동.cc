#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[301][301]; // 체스판의 이동 횟수를 저장하는 배열
bool vis[301][301]; // 방문 여부

//나이트가 이동할 수 있는 방향
int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

queue <pair<int, int >> Q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {

		int l;
		cin >> l;

		for (int j = 0; j < l; j++) fill(board[j], board[j] + l, -1); // 방문하지 않은 상태로 초기화

		int x, y, x1, y2;

		cin >> x >> y; //시작
		cin >> x1 >> y2;  //목표

		board[x][y] = 0;
		Q.push(make_pair(x, y));

		while (!Q.empty()) {
			auto cur = Q.front();
			Q.pop();

			for (int dir = 0; dir < 8; dir++) {
				int nx = dx[dir] + cur.X;
				int ny = dy[dir] + cur.Y;

				if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue; // 체스판 범위 초과
				if (board[nx][ny] >= 0) continue; // 이미 방문한 곳 건너뛰기

				board[nx][ny] = board[cur.X][cur.Y] + 1; // 이동 횟수 증가 (이전 좌표의 이동 횟수 + 1)
				Q.push({ nx, ny });
			}
		}
		cout << board[x1][y2] << "\n"; //최소 이동 횟수 저장
	}
	

	return 0;
}