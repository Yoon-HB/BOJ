#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    
    vector<int> res;
    int sum =0;
    int size = elements.size();
    
    //원형큐를 구현(?)하기 위해 벡터에 원소 값 추가
    for(int i =0; i < size; i++){
        elements.push_back(elements[i]);
    }

    for(int i = 1; i <= size; i++){
        for(int j = 0; j < size; j++ ){
            for(int k =j; k < j+i; k++){
                sum += elements[k];
            }
            res.push_back(sum);
            // cout<< sum << "\n";
            sum = 0;
        }
    }
    //중복제거
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    answer = res.size();
    
    return answer;
}