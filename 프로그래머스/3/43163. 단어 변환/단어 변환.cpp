#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;




//한 글자만 다른지 확인하는 함수
bool checkStr(string str1, string str2){
    int len = str1.length();
    bool flag = false;
    
    for(int i =0; i < len; i++){
        if(str1[i] == str2[i]) continue;
        else {
            if(flag) return false;
            flag = true;
        }
    }
    return flag;
}

//begin의 첫 문자부터 바꿀때 시작인가?
//만약 없거나 두글자 이상 바꿔야 하면 그 다음 문자로 넘어가?
//아니면 문자 하나하나 바꾸면서? 배열에서 찾아야 하나?
//결론? 백트래킹? DFS 또는 BFS
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int cnt = 0;
    
    vector<int> vis(words.size(), 0);
    
    queue<pair<string, int>> q;
    q.push({begin, cnt});
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        if(cur.X == target){
            answer = cur.Y;
            break;
        }
        
        for(int i =0; i < words.size(); i++){
            if(checkStr(cur.X, words[i]) && !vis[i]){
                q.push({words[i], cur.Y+1});
                vis[i] = true;
            } 
            else continue;
        }
        
    }
    return answer;
}