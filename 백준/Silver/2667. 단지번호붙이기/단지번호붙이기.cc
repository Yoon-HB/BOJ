#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string board[27];
bool vis[27][27];
int n;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1};

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	//지도의 크기
	cin >> n;
	
	//N개의 자료 입력
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	int num = 0; //단지 수
	
	vector<int> v; //단지내 집수 담을 동적 배열

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == '0' || vis[i][j] == 1) continue;
			
			num++; //단지 수 증가
			queue<pair<int, int>> q;
			vis[i][j] = 1;
			q.push({ i, j });

			int area = 1;

			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) { //상하좌우 살피기
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; //범위를 벗어나면 계속
					if (vis[nx][ny] == 1 || board[nx][ny] == '0') continue;

					vis[nx][ny] = 1;
					q.push({ nx, ny });
					area++;

				}
			}
			v.push_back(area);
		}
	}
	sort(v.begin(), v.end());
	cout << num << "\n";
	for (auto i : v) {
		cout << i << "\n";
	}
	return 0;
}