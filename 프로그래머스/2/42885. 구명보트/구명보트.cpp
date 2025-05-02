#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
//2명씩 밖에 못탐;; -> 투포인터 이용

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int sum = 0;
    sort(people.begin(), people.end());
    
    int size = people.size()-1;
    int i =0;
    
    while(i <= size+1/2){
        if(people[i]+people[size] > limit){
            answer++;
            size--;
        }
        else{
            answer++;
            i++;
            size--;
        }
        
    }

    return answer;
}