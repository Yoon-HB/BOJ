#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long low = 1;
    long long high = *max_element(times.begin(), times.end()) * (long long) n; //형변환
    
    while(low <= high){
        
        long long mid = (low + high) / 2;
        long long people = 0;
        
        for(int i = 0; i < times.size(); i++){
            people += mid / times[i];
        }
        
        if(people >= n){
            answer = mid;
            high = mid - 1;
        } else{
            low = mid + 1;
        }
    }
    return answer;
}