#include <bits/stdc++.h>
using namespace std;

int N, M;

int arr[8];
vector<int> res;

void backTracking(int cnt) {
    if (cnt == M) { // M개 다 골랐다면
        for (int i = 0; i < M; i++) {
            cout << res[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        res.push_back(arr[i]);
        backTracking(cnt + 1); // 
        res.pop_back();
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    backTracking(0);


    return 0;
}
