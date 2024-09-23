#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

// 튜플 원소에 따른 정렬 필요? -> map 사용

bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.second > b.second;
}
vector<int> solution(string s) {
    vector<int> answer;
    vector<char> ch;
    map<int, int> m;
    
    
    //stoi를 활용??? 
    
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            if(s[i+1] >= '0' && s[i+1] <= '9'){
                ch.push_back(s[i]);
                continue;
            }
            else {
                ch.push_back(s[i]);
                string str = "";
                for(int j =0; j < ch.size(); j++){
                    str += ch[j];
                }
                int num = stoi(str);
                if(m.find(num) == m.end()){
                    m[num] = 1;
                } else {
                    m[num]++;
                }
                ch.clear();
            }    
        }   
    }
    
    vector<pair<int,int>> v (m.begin(),m.end());
    sort(v.begin(),v.end(),cmp);
   
    for(int i =0; i < v.size();i++){
        answer.push_back(v[i].first);
    }
    
    return answer;
}