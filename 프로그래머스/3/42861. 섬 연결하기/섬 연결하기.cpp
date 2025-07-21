#include <bits/stdc++.h>

//최소신장트리
using namespace std;
tuple<int, int, int> edge[100005]; //비용, 정점 1, 정점 2
vector<int> p(100005, -1);
int v, e;


int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v){
    u = find(u);
    v = find(v);
    
    if(u == v) return false;
    
    if(p[v] < p[u]) swap(u, v);
    if(p[u] == p[v]) p[u]--;
    p[v]  = u;
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    v = n;
    e = costs.size();
    
    for(int i =0; i < costs.size(); i++){
        int cost = costs[i][2];
        int a = costs[i][0];
        int b = costs[i][1];
        edge[i] = {cost, a, b};
    
    }
    sort(edge, edge + e);
    int cnt = 0;
    
    for(int i =0; i < e; i++){
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if(!is_diff_group(a,b)) continue;
        cnt++;
        answer += cost;
        if(cnt == v-1) break;
    }
    return answer;
}