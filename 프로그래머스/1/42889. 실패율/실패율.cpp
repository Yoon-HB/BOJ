#include <bits/stdc++.h>
// #include <string>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// #include <utility>

using namespace std;
/* 실패율 = 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수
실패율이 높은 스테이지부터 내림차순으로 스테이지의 번호가 담겨있는 배열을 return
실패율이 같은 스테이지가 있다면 작은 번호의 스테이지가 먼저 오도록
"스테이지에 도달한 유저가 없는 경우 해당 스테이지의 실패율은 0 으로 정의한다."
*/

bool compare(pair<double, int>& a, pair<double, int>& b) { //fisrt 기준으로 내림차순 정렬, second는 오름차순 정렬
    if(a.first == b.first) {
        return a.second < b.second;
    }
        
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> fail;   //pair 이용
    
    int *arr = new int[N+1]{0, };
    
    for(int i = 0; i < stages.size(); i++){
        arr[stages[i]]++;            //각 스테이지에 도달한 유저
    }
    
    int success = stages.size();   //스테이지에 도달한 플레이어 수
    double failure = 0;   //실패율
    
    for(int i =1; i <= N; i++){
        if(success == 0){     //스테이지에 도달한 플레이어 수가 0이면
            fail.push_back(make_pair(0.0, i));  //실패율을 0으로 설정
            continue;
        }
        else{
            failure = arr[i] / (double)success;  //실패율 계산
            fail.push_back(make_pair(failure, i));
            success -= arr[i];   //스테이지에 도달한 플레이어 수 계산
        }
    }
    sort(fail.begin(), fail.end(), compare); //정렬
    
    for(int i =0; i < N; i++){
        answer.push_back(fail[i].second);
    }
    
    return answer;
}