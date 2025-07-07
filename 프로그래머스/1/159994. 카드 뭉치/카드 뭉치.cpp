#include<bits/stdc++.h>


using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    queue<string> c1, c2, g;
    for(auto i : cards1){
        c1.push(i);
    }
    for(auto i : cards2){
        c2.push(i);
    }
    for(auto i : goal){
        g.push(i);
    }
    
    while(!g.empty()){
        if(!c1.empty() && c1.front() == g.front()){
            g.pop();
            c1.pop();
        }
        else if(!c2.empty() && c2.front() == g.front()){
            g.pop();
            c2.pop();
        } else break;
    }
    
    if(g.empty()) answer = "Yes";
    else answer = "No";
    
    return answer;
}