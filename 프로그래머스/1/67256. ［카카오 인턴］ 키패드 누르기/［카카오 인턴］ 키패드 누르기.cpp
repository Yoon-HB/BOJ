#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

unordered_map<int, pair<int, int>> keypad;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    //키보드 위치 저장 배열 필요
    
    keypad[1] = {0, 0}; keypad[2] = {0, 1}; keypad[3] = {0, 2};
    keypad[4] = {1, 0}; keypad[5] = {1, 1}; keypad[6] = {1, 2};
    keypad[7] = {2, 0}; keypad[8] = {2, 1}; keypad[9] = {2, 2};
    keypad[0] = {3, 1}; 
       
    pair<int, int> r = {3, 2};
    pair<int ,int> l = {3, 0};
    
    for(int i : numbers){
        if(i == 1 || i == 4 || i == 7 ){
            answer+= "L";
            l = keypad[i];
        }
        else if(i == 3 || i == 6 || i == 9){
            answer+= "R";
            r = keypad[i];
        }
        else{
            int dis_r = abs(r.X - keypad[i].X) + abs(r.Y - keypad[i].Y);
            int dis_l = abs(l.X - keypad[i].X) + abs(l.Y - keypad[i].Y);
            if(dis_r < dis_l){
                answer += "R";
                r = keypad[i];
            }
            else if (dis_r > dis_l){
                answer += "L";
                l = keypad[i];
            } else{
                if(hand == "right") {
                    answer += "R";
                    r = keypad[i];
                }
                else {
                    answer += "L";
                    l = keypad[i];
                }               
            }                       
        }           
    }
    return answer;
}