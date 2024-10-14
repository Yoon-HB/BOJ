#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    for(int i = l; i <= r; i++) {
        string num = to_string(i); //int ->  string으로 형변환
        
        if(i % 5 == 0) { //일단 5의 배수
            bool flag = false;
            for(int j = 0; j < num.size(); j++) { //문자열 길이만큼
                if(num[j] == '0' || num[j] == '5') flag = true; // 문자가 0이거나 5이면은 true
                else {
                    flag = false; //아니면 false
                    break;
                }
            }
            if(flag) answer.push_back(i);  //true이면 정답
        }
    }
    if(answer.empty()) answer.push_back(-1); //그러한 정수가 없다면, -1이 담긴 배열 return
    
    return answer;
}