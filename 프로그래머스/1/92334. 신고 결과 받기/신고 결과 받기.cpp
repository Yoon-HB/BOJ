#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string, unordered_set<string>> user;
    unordered_map<string, int> cnt;
    
    for(int i =0; i <report.size(); i++){
        stringstream ss(report[i]);
        string use_id, reported;
        ss >> use_id >> reported;
        user[reported].insert(use_id);
    }
    
    for(auto iter = user.begin(); iter != user.end(); iter++){
        if(iter->second.size() >= k){
            for(auto& reporter : iter->second){
                cnt[reporter]++;
            }
        }
    }
    for(auto& id : id_list){
        answer.push_back(cnt[id]);
    }
    
    
    return answer;
}