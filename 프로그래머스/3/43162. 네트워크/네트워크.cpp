#include <bits/stdc++.h>
using namespace std;
vector<int> adj[203];
bool vis[203] = {false};


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    queue<int> q;
    
    for(int i =0; i < computers.size(); i++){
        for(int j = 0; j < n; j++){
            if(j != i && computers[i][j] == 1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        answer++;
        
        q.push(i);
        vis[i] = true;
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            
            for(auto nxt : adj[cur]){
                if(vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }
    
    return answer;
}