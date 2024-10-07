#include <bits/stdc++.h>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    
    bool visited[11][11] = { false };
    
    // 출발 정점은 문제에선 (0, 0)긴한데 각 좌표를 배열로 다루기 위해 (5, 5)로 치환함. 좌상단이 배열 인덱스로 [0][0]가 되게끔 하기 위하여.
    int curX = 5;
    int curY = 5;
    
    visited[curX][curY] = true; // 출발지는 미리 방문 체크
    
    for(int i = 0; i < dirs.length(); i++){
        int startX = curX; // 현재 간선에서의 출발 정점 X좌표
        int startY = curY; // 현재 간선에서의 출발 정점 Y좌표
        
        /* 이동 */
        if (dirs[i] == 'U'){
            if (curX - 1 < 0)
                continue;
            curX--;
        }
        if (dirs[i] == 'D'){
            if (curX + 1 > 10)
                continue;
            curX++;
        }
        if (dirs[i] == 'L'){
            if (curY - 1 < 0)
                continue;
            curY--;
        }
        if (dirs[i] == 'R'){
            if (curY + 1 > 10)
                continue;
            curY++;
        }
        
        // 출발정점, 도착정점 둘 다 방문한적 있다면 무시    
        if (visited[startX][startY] == true && visited[curX][curY] == true) continue;
        else{
            visited[curX][curY] = true; // 방문 체크
            cout<<  curX << "," << curY << "\n";
            answer++; // answer 증가
            
        }
        
    }
    return answer;
}