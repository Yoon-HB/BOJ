#include <bits/stdc++.h>
using namespace std;

//11번이 틀리는 이유 -> 모든 정수가 0일 경우

//새로운 정렬 조건 -> 문자열 이기에 값을 더해서 비교 ex) 34 3 -> 343 > 334
bool cmp(string &a, string &b){
    if( a+b > b+a) {
        return true;    
    } else return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> number;
    
    int cnt = 0;
    //정수형을 문자열로 바꾸기
    for(int i =0; i < numbers.size(); i++){
        if(numbers[i] == 0) cnt++;
        number.push_back(to_string(numbers[i]));
    }
    //0이면 answer는 0
    if(cnt == numbers.size()){
        answer = "0";
        return answer;
    }
    
    //정렬
    sort(number.begin(), number.end(), cmp);

    //하나의 문자열로 연결
    for(int i =0; i < number.size(); i++){
        answer += number[i];
    }

    return answer;
}