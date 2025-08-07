#include <bits/stdc++.h>
using namespace std;

//책 참고해서 풀음. 신기하다. 이런 생각 어떻게 하는거지...
int solution(vector<vector<int>> board)
{
    int answer = 0;
    
    for(int i = 1; i < board.size(); i++){
        for(int j =1; j < board[i].size(); j++){
            if(board[i][j] == 1){
                int up = board[i-1][j];
                int left = board[i][j-1];
                int cross = board[i-1][j-1];
                
                board[i][j] = min(up, min(left, cross)) + 1;
            }
        }
    }
    int max_len = 0;
    
    for(const auto& row : board){
        max_len = max(max_len, *max_element(row.begin(), row.end()));
    }
    
    answer = max_len * max_len;
    
    

    return answer;
}