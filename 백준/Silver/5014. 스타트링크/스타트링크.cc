#include <bits/stdc++.h>
using namespace std;

#define X first;
#define Y second;

int F, S, G, U, D;
bool vis[1000002];

int bfs() {
    queue<pair<int, int>> q;
    q.push({ S, 0 });  // 시작층 S, 버튼 누른 횟수 0
    vis[S] = true;

    while (!q.empty()) {
        int cur = q.front().X;
        int btn = q.front().Y;

        q.pop();

        if (cur == G) return btn;  // 목표층 도착 시 버튼 횟수 반환

        // 위로 이동
        if (cur + U <= F && !vis[cur + U]) {
            vis[cur + U] = true;
            q.push({ cur + U, btn + 1 });
        }

        // 아래로 이동
        if (cur - D >= 1 && !vis[cur - D]) {
            vis[cur - D] = true;
            q.push({ cur - D, btn + 1 });
        }
    }

    return -1;  // 목표층 도달 불가능
}

int main() {
    cin >> F >> S >> G >> U >> D;

    int res = bfs();
    if (res == -1) cout << "use the stairs";
    else cout << res;

    return 0;
}
