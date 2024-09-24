#include <string>
#include <vector>

using namespace std;

int cnt = 0;
int answer = -1;
string str = "AEIOU";

void dfs(string start ,string word){

    if(cnt == answer ) return;
    
    for(int i =0; i < 5; i++){

        start += str[i];
        cnt++;
        
        if(start == word){
            answer = cnt;
            return;
        }
        
        if(start.length() < 5){
            dfs(start, word);
        }
        start.pop_back();
        
    }
}
int solution(string word) {
     dfs("", word);
    
    return answer;
}