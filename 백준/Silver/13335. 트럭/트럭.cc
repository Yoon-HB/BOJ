#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
    int bridge_length;
    int weight;
    int n;
    vector<int> truck_weights;

    cin >> n >> bridge_length >> weight;

    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        truck_weights.push_back(w);
    }

    int answer = 1;
    queue<pair<int, int>> q;  //다리에 있는 트럭
    queue<pair<int, int>> truck; //다리 건너기 전 트럭

    int sum_weight = 0; //다리 위에 있는 트럭들의 무게 합
    int cnt = 0; //다리 건넌 트럭 개수

    for (int i = 0; i < truck_weights.size(); i++) {
        truck.push(make_pair(truck_weights[i], 0));
    }


    while (cnt < truck_weights.size()) {
        if (truck.empty()) { //다리를 건너야 되는 트럭이 없을 경우

            // cout << "트럭이 비었을 떼"<<q.size() << "\t" << answer <<"\n";
            while (!q.empty()) { //다리 위 트럭이 없을 때까지 시간 돌리기
                if (answer - q.front().second == bridge_length) {
                    sum_weight -= q.front().first;
                    q.pop(); //다리를 지난 트럭
                }
                answer++;
            }
            cout << answer;
            return 0;
            //return answer;
        }
        //다리 위에 갈 수 있는 조건
        if (q.size() < bridge_length && truck.front().first + sum_weight <= weight) {
            q.push(make_pair(truck.front().first, answer - 1));
            sum_weight += truck.front().first;
            truck.pop();
        }

        if (answer - q.front().second == bridge_length) {
            sum_weight -= q.front().first;
            //cout << q.front().first << q.front().second << " answer:" << answer << "\n";
            q.pop(); //다리를 지난 트럭
            cnt++;
        }
        answer++;
    }
    cout << answer;

    return 0;
	
}

