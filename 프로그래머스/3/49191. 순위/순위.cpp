#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    bool D[102][102] = {false}; // D[i][j] = i가 j를 이김

    for (auto r : results) {
        int a = r[0], b = r[1];
        D[a][b] = true;
    }

    // 플로이드 알고리즘
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (D[i][k] && D[k][j])
                    D[i][j] = true;
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (D[i][j] || D[j][i]) count++;
        }
        if (count == n - 1) answer++;
    }

    return answer;
}
