#include <bits/stdc++.h>

using namespace std;
unordered_set<int> res;

bool isprime(int n){
	if(n <=1) return 0;
	for(int i =2; i*i <= n; i++){
		if(n%i == 0) return 0;
	}
	return 1;
}

void dfs(string str, string cur, vector<bool>& vis){ //배열을 참조로 전달해야 함;;
    if(!cur.empty()){
        int num = stoi(cur);
        res.insert(num);
    }
    
    for(int i=0; i < str.size();i++){
        if(vis[i]) continue;
        vis[i] = true;
        dfs(str, cur+str[i], vis);
        vis[i]= false;
    }
}
int solution(string numbers) {
    int answer = 0;
    
    vector<bool> vis(numbers.size(), false);
    dfs(numbers, "", vis);
    
    for(auto iter = res.begin(); iter != res.end(); iter++){
        if(isprime(*iter)) {
            cout << *iter << "\n";
            answer++;
        }
    }
    return answer;
}