#include <bits/stdc++.h>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (string skill_tree : skill_trees) {
        queue<char> q;
        int abc[27] = {0}; //매번 초기화 필요

        // skill 순서를 q에 저장 + abc 배열 초기화
        for (char s : skill) {
            abc[s - 'A'] = 1;
            q.push(s);
        }

        bool valid = true; //올바른 스킬트리인지 확인하는 변수
        
        // 스킬트리를 하나씩 확인
        for (char ch : skill_tree) {
            int num = ch - 'A';
            
            if (!q.empty() && q.front() == ch) {
                q.pop(); //맞으면 순서대로 pop
            } 
            else if (abc[num] > 0) { 
                //스킬 순서가 틀리면 실패
                valid = false;
                break;
            }
        }
        
        if (valid) { //올바른 스킬트리라면 정답 증가
            answer++;
        }
    }
    
    return answer;
}
