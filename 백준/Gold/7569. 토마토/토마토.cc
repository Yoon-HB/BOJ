#include <bits/stdc++.h>

using namespace std;

//tuple 접근방식!
#define X get<2>
#define Y get<1>
#define Z get<0>

int arr[102][102][102];
int dist[102][102][102];

int M, N, H;

int dx[6] = { 1, 0, -1, 0, 0, 0 }; //위, 아래 확인 추가
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N >> H;

    queue<tuple<int, int, int>> q; //2개는 'pair' 3개는 'tuple';

    //좌표 순서 조심하기

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> arr[i][j][k];
                if (arr[i][j][k] == 1)
                    q.push({ i, j, k });
                if (arr[i][j][k] == 0)
                    dist[i][j][k] = -1;
            }
        }
    }

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = X(cur), y = Y(cur), z = Z(cur);
        for (int dir = 0; dir < 6; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];
            if (nx < 0 || nx >= M || ny < 0 || ny >= N || nz < 0 || nz >= H) continue;
            if (dist[nz][ny][nx] >= 0) continue;
            dist[nz][ny][nx] = dist[z][y][x] + 1;
            q.push({ nz, ny, nx });  
        }
    }

    int ans = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (dist[i][j][k] == -1) {
                    cout << -1;
                    return 0;
                }
                ans = max(ans, dist[i][j][k]);
            }
        }
    }

    cout << ans;

    return 0;
}
