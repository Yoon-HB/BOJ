#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    while (1) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        vector<int> adj[502];
        bool vis[502] = { 0 };

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int cnt = 0;

        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;

            queue<pair<int, int>> q;
            q.push({ i, -1 });
            vis[i] = true;
            bool isTree = true;

            while (!q.empty()) {
                int cur = q.front().first;
                int parent = q.front().second;
                q.pop();

                for (int nxt : adj[cur]) {
                    if (nxt == parent) continue; // 부모 노드는 무시
                    if (vis[nxt]) {
                        isTree = false; // 부모가 아닌데 이미 방문 → 사이클
                        continue;
                    }
                    vis[nxt] = true;
                    q.push({ nxt, cur });
                }
            }

            if (isTree) cnt++;
        }

        if (cnt == 0)
            cout << "Case " << tc << ": No trees.\n";
        else if (cnt == 1)
            cout << "Case " << tc << ": There is one tree.\n";
        else
            cout << "Case " << tc << ": A forest of " << cnt << " trees.\n";

        tc++;
    }
    return 0;
}
