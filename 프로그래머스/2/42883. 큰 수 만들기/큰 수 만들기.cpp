#include<bits/stdc++.h>

using namespace std;
//다른 풀이 참고하여서 푼 문제...
string solution(string number, int k) {
    string answer = "";
    
    int idx = 0;
    for(int i =0; i < number.length()-k; i++){
        char maxChar = ' ';
        
        for(int j = idx; j <= k+i; j++){
            if(maxChar < number[j]){
                maxChar = number[j];
                idx = j+1;
            }
        }
        answer += maxChar;
    }
    return answer;
}