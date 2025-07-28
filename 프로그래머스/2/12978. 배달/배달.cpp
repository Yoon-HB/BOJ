#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int INF = 1e9;
vector<pair<int,int>> adj[2005];
int dis[52];


int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    //정점 a, b 걸리는 시간 c
    for(int i =0; i < road.size(); i++){
        adj[road[i][0]].push_back({road[i][1], road[i][2]});
        adj[road[i][1]].push_back({road[i][0], road[i][2]});
        
    }
    
    fill(dis, dis+N+1, INF);
    dis[1]= 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    
    while(!pq.empty()){
        auto cur = pq.top();
		pq.pop();
        
        if (dis[cur.Y] != cur.X) continue;
        
		for (auto nxt : adj[cur.Y]) {
			if (dis[nxt.X] <= dis[cur.Y] + nxt.Y) continue;
			dis[nxt.X] = dis[cur.Y] + nxt.Y;
			pq.push({ dis[nxt.X],nxt.X });
		}
	}
    
    for(int i = 1; i <= N; i++){
        if(dis[i] <= K) answer++;
    }

    return answer;
}