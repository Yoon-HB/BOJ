//https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x0C/solutions/15650.cpp 참고
#include <bits/stdc++.h>

using namespace std;
int N, M;
int arr[10];
int isused[10];

void func(int k) { // 현재 k개까지 수를 택했음.
    if (k == M) { // m개를 모두 택했으면

        for (int i = 0; i < M; i++) {

            cout << arr[i] << ' '; // arr에 기록해둔 수를 출력
            isused[i] = 1;
        }
        cout << '\n';
        return;
    }

    int st = 1; // 시작지점, k = 0일 때에는 st = 1
    if (k != 0) st = arr[k - 1] + 1; // k != 0일 경우 st = arr[k-1]+1

    for (int i = st; i <= N; i++) {
        arr[k] = i; // k번째 수를 i로 정함
        func(k + 1); // 다음 수를 정하러 한 단계 더 들어감
    }
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);


	cin >> N >> M;

    func(0);

    return 0;

}