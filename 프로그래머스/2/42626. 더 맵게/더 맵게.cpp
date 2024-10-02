#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    //우선순위큐 -> 오름차순
    priority_queue<int, vector<int>, greater<int>> pq;
    
    //큐에 담기
    for(int i =0; i < scoville.size(); i++){
        pq.push(scoville[i]);
    }
    
    while(1){
        if(pq.size() == 1) {
            if(pq.top() < K )
                return -1;
        }
        if(pq.top() < K){
            int a = pq.top(); //가장 작은 지수
            pq.pop();  
            int b = pq.top(); //두 번째로 작은 지수
            pq.pop();
            
            int mix = a + (b*2); //섞은 스코빌 지수
            answer++; //섞는 횟수 증가
            
            pq.push(mix); //섞은 스코빌 추가
            
        } else {
            break;
        }
    }
    
    
    
    return answer;
}