#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// 목표 문자까지의 최단 거리 반환 (없으면 -1)
int bfs(int sx, int sy, char target, vector<string>& maps) {
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    
    queue<pair<int, int>> q;
    q.push({sx, sy});
    
    vis[sx][sy] = true;
    int dist = 0;

    while (!q.empty()) {
        int sz = q.size();
        
        while (sz--) {
            auto [x, y] = q.front(); 
            q.pop();
            
            if (maps[x][y] == target) return dist;
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (vis[nx][ny] || maps[nx][ny] == 'X') continue;
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        dist++;
    }
    return -1;
}

int solution(vector<string> maps) {
    int n = maps.size();
    int m = maps[0].size();
    int sx, sy, lx, ly;

    // 시작점(S)과 레버(L) 좌표 찾기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maps[i][j] == 'S') tie(sx, sy) = {i, j};
            if (maps[i][j] == 'L') tie(lx, ly) = {i, j};
        }
    }

    int toLever = bfs(sx, sy, 'L', maps);
    int toExit = bfs(lx, ly, 'E', maps);

    if (toLever == -1 || toExit == -1) return -1;
    return toLever + toExit;
}
