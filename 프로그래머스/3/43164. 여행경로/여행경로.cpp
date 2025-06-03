#include <bits/stdc++.h>

using namespace std;
unordered_map<string, priority_queue<string, vector<string>, greater<string>>> airport;
vector<string> answer;

void dfs(string cur){
    while(!airport[cur].empty()){
        string nxt = airport[cur].top();
        airport[cur].pop();
        dfs(nxt);
    }
    answer.push_back(cur);
}
vector<string> solution(vector<vector<string>> tickets) {
    
    for(int i =0; i < tickets.size(); i++){
        airport[tickets[i][0]].push(tickets[i][1]);
    }

    dfs("ICN");
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}