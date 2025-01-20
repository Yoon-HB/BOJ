#include <bits/stdc++.h>

using namespace std;

vector<int> adj[20001];
int dist[20001];

void bfs(){
    fill(dist, dist+20001, -1);
    
    queue<int> q;
    q.push(1);
    
    dist[1] = 0;
    
    while(!q.empty()){
        int cur = q.front();
        
        q.pop();
        
        for(auto nxt : adj[cur]){
            if(dist[nxt] != -1) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
}

//간선은 양방향
int solution(int n, vector<vector<int>> edge) {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int answer = 0;
    
    for(int i =0; i < edge.size(); i++){
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
    bfs();
    
    sort(dist, dist+20001, greater<int>());
    
    for(int i =0 ; i < 20001; i++){
        if(dist[i] == dist[i+1]) answer++;
        else break;
    }
    
    return answer+1;
}