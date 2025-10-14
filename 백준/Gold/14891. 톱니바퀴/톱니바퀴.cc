#include <bits/stdc++.h>
using namespace std;

vector<int> arr[5];

// 시계 방향 회전
void turn(int n) {
    rotate(arr[n].rbegin(), arr[n].rbegin() + 1, arr[n].rend());
}

// 반시계 방향 회전
void rturn(int n) {
    rotate(arr[n].begin(), arr[n].begin() + 1, arr[n].end());
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= 4; i++) {
        string str;
        cin >> str;
        for (char c : str) arr[i].push_back(c - '0');
    }

    int K;
    cin >> K;

    while (K--) {
        int n, d;
        cin >> n >> d;

        int dir[5] = { 0 }; // 각 톱니 회전 방향
        dir[n] = d;

        // 왼쪽 전파
        for (int i = n - 1; i >= 1; i--) {
            if (arr[i][2] != arr[i + 1][6]) dir[i] = -dir[i + 1];
            else break;
        }

        // 오른쪽 전파
        for (int i = n + 1; i <= 4; i++) {
            if (arr[i - 1][2] != arr[i][6]) dir[i] = -dir[i - 1];
            else break;
        }

        // 회전 적용
        for (int i = 1; i <= 4; i++) {
            if (dir[i] == 1) turn(i);
            else if (dir[i] == -1) rturn(i);
        }
    }

    int ans = 0;
    int score = 1;
    for (int i = 1; i <= 4; i++) {
        if (arr[i][0] == 1) ans += score;
        score *= 2;
    }

    cout << ans;
    return 0;
}
