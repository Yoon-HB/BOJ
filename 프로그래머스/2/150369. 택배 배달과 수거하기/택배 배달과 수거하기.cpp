#include <bits/stdc++.h>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    //일단은 거리가 먼 집부터 해결해야 해...

    long long del = 0;
    long long pick= 0;
    
    for(int i = n-1; i >= 0; i--){  
        del += deliveries[i];
        pick += pickups[i];
        
        while (del > 0 || pick > 0) {
            
            answer += (i + 1) * 2;
            
            del -= cap;
            pick -= cap;
        }
            
    }
    return answer;
}