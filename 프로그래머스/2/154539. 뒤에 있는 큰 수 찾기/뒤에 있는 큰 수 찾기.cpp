#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
//중첩 반복문 -> 시간 초과 => stack 이용해서 풀기
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> st;
    
    for(int i = numbers.size()-1; i >= 0; i--){ 
        while(1){
            if(st.empty()){
                answer.push_back(-1);
                break; 
            }
            
            if(numbers[i] < st.top()){
                answer.push_back(st.top());
                break;
            }
            st.pop();
        }
        st.push(numbers[i]);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}