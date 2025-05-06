#include <bits/stdc++.h>
using namespace std;
int N, M;

int arr[8]; 

void backTracking(int cnt) {
    if (cnt == M) { // M개 다 골랐다면
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) { 
        arr[cnt] = i;
        backTracking(cnt + 1);
    }
}

int main() {
    cin >> N >> M;
    backTracking(0);

    return 0;
}