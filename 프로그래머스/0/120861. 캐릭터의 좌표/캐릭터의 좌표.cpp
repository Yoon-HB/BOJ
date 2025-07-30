#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;

    int maxX = board[0] / 2;
    int maxY = board[1] / 2;

    int x = 0, y = 0;

    for (string key : keyinput) {
        int nx = x, ny = y;

        if (key == "left") nx--;
        else if (key == "right") nx++;
        else if (key == "up") ny++;
        else if (key == "down") ny--;

        if (abs(nx) <= maxX && abs(ny) <= maxY) {
            x = nx;
            y = ny;
        }
    }

    answer.push_back(x);
    answer.push_back(y);
    
    return answer;
}
