#include <bits/stdc++.h>
using namespace std;

int DP[102][102]; // 해당 위치까지의 최단 경로 개수 배열

int solution(int m, int n, vector<vector<int>> puddles) {
    DP[1][1] = 1; 

    // 물웅덩이 위치를 -1로 표시
    for (int i = 0; i < puddles.size(); i++) {
        DP[puddles[i][1]][puddles[i][0]] = -1;  // (y, x) 순서로 저장
    }

    for (int i = 1; i <= n; i++) {  
        for (int j = 1; j <= m; j++) {  
            if (i == 1 && j == 1) continue; // 시작점 유지
            
            if (DP[i][j] == -1) {  
                DP[i][j] = 0;  // 물웅덩이 위치는 0으로 설정
                continue;
            }
            
            DP[i][j] = (DP[i-1][j] + DP[i][j-1]) % 1000000007; //왼쪽+위
        }
    }

    int answer = DP[n][m];
    return answer;
}
