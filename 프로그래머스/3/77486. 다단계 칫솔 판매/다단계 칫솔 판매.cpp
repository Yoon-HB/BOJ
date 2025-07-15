#include<bits/stdc++.h>
using namespace std;

//이익은 개당 100 원

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    unordered_map<string, string> um; //판매 - 추천인
    unordered_map<string, int> price; //직원 - 수익
    
    for(int i =0; i < enroll.size(); i++){
        um[enroll[i]] = referral[i];
    }
    
    for(auto x : enroll){
        price[x] = 0;
    }
    
    for(int i =0; i < seller.size(); i++){
        int money = amount[i]*100;
        string name = seller[i];
        
        while(money > 0 && name != "-"){
            int share = money * 0.1;
            price[name] += (money - share);
            
            if(um.find(name) != um.end()){
                name = um[name];
            }
            else break;
            
            money = share; //10% 뗀거에서 계속 해서 떼야하니까 반복
        }
    }
    
    answer.reserve(enroll.size());
    
    for(auto& n : enroll){
        answer.push_back(price[n]);
    }
    
    return answer;
}