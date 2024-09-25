#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    //map을 사용하여 관리
    map<int, int> m1, m2;
    int answer = 0;
    
    //동생이 일단 한 판 다가지고 있음
    for(int i =0; i < topping.size(); i++){
        m2[topping[i]]++;
    }
   
    //동생이 형에게 하나씩 토핑 나눠줌
    for(int i =0; i < topping.size(); i++){
        if(m2.find(topping[i]) != m2.end()){
            m1[topping[i]]++;
            m2[topping[i]]--;
            //동생 토핑이 0개이면 갯수 지우기
            if(m2[topping[i]] == 0) m2.erase(topping[i]);
        }       
        //토핑 개수가 같으면 답 증가
        if(m1.size() == m2.size()) answer++;
    } 
    
    return answer;
}