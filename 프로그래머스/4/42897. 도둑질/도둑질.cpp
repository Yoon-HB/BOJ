#include <bits/stdc++.h>

using namespace std;


int solution(vector<int> money) {
    int answer = 0;

    vector<int> dp1(money.size(), 0);
    vector<int> dp2(money.size(), 0);
    
    //기준 집을 털 경우
    
    dp1[0] = money[0];
    dp1[1] = money[0];
    
    for(int i = 2; i < money.size()-1; i++){
        dp1[i] = max(dp1[i-1], dp1[i-2] + money[i]);
    }
    
    //기준 집을 안 털 경우
    
    dp2[1] = money[1];
    
    for(int i = 2; i < money.size(); i++){
        dp2[i] = max(dp2[i-1], dp2[i-2] + money[i]);
    }
    
    answer = max(dp1[money.size()-2], dp2[money.size()-1]);
    
    return answer;
}