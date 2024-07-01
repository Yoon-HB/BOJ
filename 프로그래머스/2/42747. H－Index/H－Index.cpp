#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
int arr[100001];
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int m = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    
    for(int i= 0; i < citations.size(); i++){
        if(citations[i] < i+1){
            answer = i;
            return answer;
        }
    }
    return citations.size();
}