#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;
//답 참고하여 푼 문제
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> m;
    
    for(int i =0; i < clothes.size(); i++){
        m[clothes[i][1]]++;
    }

    for(auto i : m){
        answer *= (i.second+1);  //입거나 안입거나 
    }
    
    return answer -1; //아무것도 안입은 경우 제외
}