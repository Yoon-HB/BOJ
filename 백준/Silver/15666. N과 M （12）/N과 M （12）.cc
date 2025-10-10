#include <bits/stdc++.h>
using namespace std;

int N, M;

//int arr[8];
vector<int> arr;
vector<int> res;

void backTracking(int cnt, int st) {
    if (cnt == M) { // M개 다 골랐다면
        for (int i = 0; i < M; i++) {
            cout << res[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = st; i < arr.size(); i++) {

        res.push_back(arr[i]);
        backTracking(cnt + 1, i);
        res.pop_back();
       
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        //cin >> arr[i];
        int num;
        cin >> num;
        arr.push_back(num);
    }
    
    //sort(arr, arr + N);
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    

    backTracking(0, 0);


    return 0;
}
