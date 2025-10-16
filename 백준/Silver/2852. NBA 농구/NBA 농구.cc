#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int a = 0, b = 0;
    int suma = 0, sumb = 0;
    int prev = 0; // 직전 득점 시간(초)

    for (int i = 0; i < N; i++) {
        int team;
        string goal;

        cin >> team >> goal;

        int g = stoi(goal.substr(0, 2)) * 60 + stoi(goal.substr(3, 2)); // 득점 시각(초)

        if (a > b) suma += g - prev;
        else if (b > a) sumb += g - prev;

        // 득점 반영
        if (team == 1) a++;
        else b++;

        prev = g;
    }

    // 경기 종료 시점(48분 = 2880초)까지 리드 시간 추가
    if (a > b) suma += 2880 - prev;
    else if (b > a) sumb += 2880 - prev;

    // MM:SS 형식으로 출력
    auto printTime = [](int t) {
        printf("%02d:%02d\n", t / 60, t % 60);
    };

    printTime(suma);
    printTime(sumb);

    return 0;
}
