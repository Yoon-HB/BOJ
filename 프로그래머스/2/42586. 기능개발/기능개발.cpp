#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue <int> q, st;
    
    //남은 일 수 구하기
    for(int i =0; i < progresses.size(); i++){
        int n = 100 - progresses[i];
        int div = n/speeds[i];
        if(n%speeds[i] != 0){
            div += 1;
        }
        q.push(div);
        cout << q.back() << " ";
    }
    
    //스택이 비어있거나 큐에 있는 값이 크면 st.push
    //st.front()보다 q.front()가 크면 스택의 사이즈를 answer에 삽닙
    //st.front()보다 작으면 st.push
    while(!q.empty()){
        if(st.empty()){
            st.push(q.front());
            q.pop();
        }
        else if(q.front() > st.front()){
            answer.push_back(st.size());
            while( !st.empty() ) {
                st.pop();
            }
                
        }else if(q.front() <= st.front()){
            st.push(q.front());
            q.pop();
        }
        
    }
    answer.push_back(st.size());
    
    
    return answer;
}