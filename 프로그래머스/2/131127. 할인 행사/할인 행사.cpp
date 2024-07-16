#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    for(int i =0; i <= discount.size()-10; i++){
        map<string, int> m;  //초기화
        for(int k =0; k < want.size(); k++){  //map에 담기
            m.insert({want[k], number[k]});
        }
        bool flag = true;
        
        for(int j =0; j < 10; j++){  //10일 동안
            if(m.find(discount[i+j]) != m.end()){  //map에 존재하면
                if(m[discount[i+j]] == 0){   //map에 존재하지만 수량이 일치하지 않을 경우
                    flag= false;
                    m.clear();
                    break;
                }
                else{  
                    m[discount[i+j]]--;
                }
            } else{ //존재하지 않으면
                flag = false;
                break;
            }  
        }
        if(flag) answer++;
    }
    
    return answer;
}