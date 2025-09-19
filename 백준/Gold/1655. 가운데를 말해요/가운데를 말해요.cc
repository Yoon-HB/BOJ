#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    priority_queue<int> maxHeap; // 작은 절반 그룹 (top이 그룹 내 최대)
    priority_queue<int, vector<int>, greater<int>> minHeap; // 큰 절반 그룹 (top이 그룹 내 최소)

    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;

        // 1. 일단 maxHeap에 넣고
        maxHeap.push(num);

        // 2. maxHeap의 가장 큰 값을 minHeap으로 옮겨 균형 맞추기
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // 3. 두 힙의 크기를 조절하여 maxHeap이 항상 같거나 1개 더 많도록
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        // 4. maxHeap의 top이 원하는 중앙값
        cout << maxHeap.top() << "\n";
    }
}