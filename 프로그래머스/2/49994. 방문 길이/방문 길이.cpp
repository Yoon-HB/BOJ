#include <bits/stdc++.h>
using namespace std;

//답안 참조
int solution(string dirs) {
    int answer = 0;
    map<pair<pair<int, int>, pair<int, int>>, bool> visited;
        
    int curX = 5;
    int curY = 5;
   
    
    for(int i = 0; i < dirs.length(); ++i){
        int startX = curX; // 현재 간선에서의 출발 정점 X좌표
        int startY = curY; // 현재 간선에서의 출발 정점 Y좌표
        
        /* 이동 */
        if (dirs[i] == 'U'){
            if (curX - 1 < 0) // 무시
                continue;
            curX--;
        }
        if (dirs[i] == 'D'){
            if (curX + 1 > 10) // 무시
                continue;
            curX++;
        }
        if (dirs[i] == 'L'){
            if (curY - 1 < 0) // 무시
                continue;
            curY--;
        }
        if (dirs[i] == 'R'){
            if (curY + 1 > 10) // 무시
                continue;
            curY++;
        }
        
        // 출발정점, 도착정점 둘 다 방문한적 있다면 무시    
        if (visited[make_pair(make_pair(startX, startY), make_pair(curX, curY))] == true) continue;
        else{
            visited[make_pair(make_pair(startX, startY), make_pair(curX, curY))] = true; // 방문 체크
            visited[make_pair(make_pair(curX, curY), make_pair(startX, startY))] = true; // 역방향도 체크
            
            answer++; // answer 증가
        }      
    }
    return answer;
}