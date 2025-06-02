#include <bits/stdc++.h>
using namespace std;


int solution(int n, vector<vector<int>> wires) {
    int answer = 0x7f7f7f7f;
    
    for(int i =0; i < wires.size(); i++){
        vector<int> adj[102];
        bool vis[102] = {false};
        vector<int> cnt;
        
        
        for(int j = 0; j < wires.size(); j++){
            if(i == j) continue;
            adj[wires[j][0]].push_back(wires[j][1]);
            adj[wires[j][1]].push_back(wires[j][0]);
        }
        
        queue<int> q;
        
        for(int k = 1; k <= n; k++){
            int count = 1;
            
            if(vis[k]) continue;
            
            q.push(k);
            
            vis[k] = true;
            
            while(!q.empty()){
                int cur = q.front();
                q.pop();

                for(auto nxt : adj[cur]){
                    if(vis[nxt]) continue;
                    q.push(nxt);
                    vis[nxt] = true;
                    count++;
                }
            }
            cnt.push_back(count);
        }	
        answer = min(answer, abs(cnt[0] - cnt[1]));
    }
    return answer;
}