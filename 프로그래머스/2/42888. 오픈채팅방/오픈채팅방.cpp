#include<bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> user;
    
    for(int i = 0; i < record.size(); i++){
        stringstream ss(record[i]);
        string status, id, name;
        ss >> status >> id >> name;
        
        if(status != "Leave"){
            user[id] = name;
        }
    }
    
     for(int i = 0; i < record.size(); i++){
        stringstream ss(record[i]);
        string status, id, name;
        ss >> status >> id >> name;
        
        string str = "";
        if(status == "Enter"){
            str += user[id] + "님이 들어왔습니다.";
            answer.push_back(str);
        }
        else if(status == "Leave"){
            str += user[id] + "님이 나갔습니다.";
            answer.push_back(str);
        }
    }
    
    return answer;
}