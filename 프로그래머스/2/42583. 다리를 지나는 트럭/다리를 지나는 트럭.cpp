#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    queue<pair<int, int>> q;
    queue<pair<int, int>> truck;
    
    int sum_weight = 0;
    int cnt =0;
    
    for(int i =0; i < truck_weights.size(); i++){
        truck.push(make_pair(truck_weights[i], 0));
    }
    
     while(cnt < truck_weights.size()) {
         if(truck.empty()){
             // cout << "트럭이 비었을 떼"<<q.size() << "\t" << answer <<"\n";
             while(!q.empty()){
                 if(answer - q.front().second == bridge_length){
                     sum_weight -= q.front().first;
                     q.pop(); //다리를 지난 트럭
                 }
                 answer++;
             }
             return answer;
         }
         
         if (q.size() < bridge_length && truck.front().first + sum_weight <= weight){
             q.push(make_pair(truck.front().first, answer-1));
             sum_weight += truck.front().first;
             truck.pop();
         }
         
         if(answer - q.front().second == bridge_length){
             sum_weight -= q.front().first;
             cout << q.front().first << q.front().second << " answer:" << answer << "\n";
             q.pop(); //다리를 지난 트럭
             cnt++;
         }
        answer++;
    } 
    
   
    return answer;
    
}