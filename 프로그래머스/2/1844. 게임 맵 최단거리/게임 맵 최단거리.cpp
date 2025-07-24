#include <bits/stdc++.h>

#define X first
#define Y second

int dis[502][502];
bool vis[502][502];
int dx[4] = { 1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
using namespace std;

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    int answer = 0;
    queue<pair<int, int>> q;
    
    dis[0][0] = 1;
    q.push({0,0});
    
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        
        for(int dir = 0; dir< 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx < 0 || ny <0 || nx >= n || ny >= m) continue;
            if(vis[nx][ny] || maps[nx][ny] != 1) continue;
            
            vis[nx][ny] = 1;
            dis[nx][ny] = dis[cur.X][cur.Y] +1;
            
            q.push({nx, ny});
        }
    }
    
    if(dis[n-1][m-1] == 0)
        answer = -1;
    else 
        answer = dis[n-1][m-1];
    
    return answer;
}