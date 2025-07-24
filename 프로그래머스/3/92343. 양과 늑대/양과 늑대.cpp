#include <bits/stdc++.h>

using namespace std;
vector <int> adj[18];
int ans;
vector<int> info_sw;

void dfs(int sheep, int wolf, int cur, vector<int> next){
    if(info_sw[cur])
        wolf++;
    else sheep++;
    
    if(sheep <= wolf) return;
    ans = max(ans, sheep);  
    
    for(int nxt : adj[cur]){
        next.push_back(nxt);
    }
    
    
    for(int i =0; i < next.size(); i++){
        int nxt = next[i];
        vector<int> nxt_cp = next;
        nxt_cp.erase(nxt_cp.begin() + i); //현재 방문할 노드를 후보군에서 제거
        dfs(sheep, wolf, nxt, nxt_cp);
    }
}
//info에서 0이면 양, 1아면 늑대
int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    info_sw = info;
    
    for(int i =0; i < edges.size(); i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    dfs(0, 0, 0,{});
    
    return ans;
}