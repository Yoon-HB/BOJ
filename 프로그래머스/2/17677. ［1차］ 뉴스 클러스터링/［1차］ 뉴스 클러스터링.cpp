#include <string>
#include <set>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    multiset<string> ms1, ms2;
    
    //대문자를 모두 소문자로 변형
    for(int i =0; i < str1.length(); i++){
        str1[i] = tolower(str1[i]);
    }
    for(int i =0; i < str2.length(); i++){
        str2[i] = tolower(str2[i]);
    }
    
    //str1을 ms1에 영문자인 것만 insert 
    for(int i =0; i < str1.length()-1; i++){
        string str = "";
        if((str1[i] >= 'a'&& str1[i] <= 'z') && (str1[i+1] >= 'a'&& str1[i+1] <= 'z') ){
            str += str1[i];
            str += str1[i+1];
            ms1.insert(str);
        } else {
            continue;
        }
    }
    //str2을 ms2에 영문자인 것만 insert 
    for(int i =0; i < str2.length()-1; i++){
        string str = "";
        if((str2[i] >= 'a'&& str2[i] <= 'z') && (str2[i+1] >= 'a'&& str2[i+1] <= 'z') ){
            str += str2[i];
            str += str2[i+1];
            ms2.insert(str);
        } else {
            continue;
        }
    }
    
    //공집합일 경우
    if(ms1.size() ==0 && ms2.size() == 0){
        answer = 65536;
        return answer;
    }
    
    int same = 0; //교집합 변수
    
    //str1가 str2에서 같은게 있다면 ms1 ms2 해당 원소 지우기 -> same로 교집합 원소 수
    //다 돌고 해당 ms 크기 구하기 -> 해당 크기를 더하고 교집합까지 더하면 -> 합집합 원소 수
    for(auto it= ms1.begin(); it != ms1.end(); ){
         if(ms2.find(*it) != ms2.end()) {
            ms2.erase(ms2.find(*it));
            it = ms1.erase(it);
            same++;
        } else {
           it++;
        }
    }
    // cout << "교집합: " << same << "\t" << "합집합: " << ms1.size()+ms2.size()+ same << "\n";
    
    double res = (double) same / (ms1.size()+ms2.size()+ same);
    answer = res * 65536;
    
    return answer;
}