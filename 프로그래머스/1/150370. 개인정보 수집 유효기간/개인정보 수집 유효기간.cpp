#include <bits/stdc++.h>
using namespace std;

int dateToDays(string date_str) {
    int year = stoi(date_str.substr(0, 4));
    int month = stoi(date_str.substr(5, 2));
    int day = stoi(date_str.substr(8, 2));
    return (year * 12 * 28) + (month * 28) + day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<string, int> um;

    for (auto& s : terms) {
        stringstream ss(s);
        
        string key;
        int value;
        
        ss >> key >> value;
        um[key] = value;
    }

    // 오늘 날짜 총 일수로 변환
    int today_days = dateToDays(today);

    for (int i = 0; i < privacies.size(); i++) {
        string s = privacies[i];
        
        int collection_days = dateToDays(s.substr(0, 10));
        
        string term_type = s.substr(11, 1);
        
        int term_months = um[term_type];
        
        if (today_days >= collection_days + (term_months * 28)) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}