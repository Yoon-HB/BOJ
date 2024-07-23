#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> deq; //cache
    
    int hit =0;
    int miss = 0;
    
    if (cacheSize == 0) {  //cacheSize가 0일 경우 모두 miss
        return cities.size() * 5;
    } 
    
    for(int i = 0; i < cities.size(); i++){
        int idx = 0;
        
        //대소문자 상관 없는 조건을 만족하기 위해
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        auto it = find(deq.begin(), deq.end(), cities[i]);
      
        if(it != deq.end()){  //cache hit
            deq.erase(it);  //지우고
            deq.push_back(cities[i]); //다시 최근 사용으로 넣기
            hit++;
        }
        else{  //cache miss
            if(deq.size() == cacheSize) {  //cache가 다 찼다면
                deq.pop_front();  //가장 나중거 지우고
            }
            deq.push_back(cities[i]);  //최신 넣기
            miss++;
        }
        
    }
    answer  = hit*1 + miss*5; //실행시간 계산
    
    return answer;
}