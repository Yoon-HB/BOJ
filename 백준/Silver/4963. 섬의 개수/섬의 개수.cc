#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;



int dx[8] = { 1, 0, -1, 0, -1, -1, 1, 1 };
int dy[8] = { 0, -1, 0, 1, -1, 1, -1, 1 };


int w, h;

int main() {

	while (1) {
		int cnt = 0;
		int arr[52][52] = { 0, };
		bool vis[52][52]{ 0, };

		cin >> w >> h;
		
		if (w == 0 && h == 0) return 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] == 0 || vis[i][j]) continue;
				cnt++;

				queue<pair<int, int>> q;
				q.push({ i,j });

				while (!q.empty()) {
					auto cur = q.front();
					q.pop();

					for (int dir = 0; dir < 8; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
						if (vis[nx][ny] == 1 || arr[i][j] != arr[nx][ny]) continue;
						
						vis[nx][ny] = 1;
						q.push({ nx, ny });
					}
				}
			}
		}

		cout << cnt << "\n";

	}
	
}