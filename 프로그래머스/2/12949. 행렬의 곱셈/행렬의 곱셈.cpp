#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    // cout<< arr1[0].size();
    for(int i =0; i < arr1.size(); i++){
        vector<int> res;
        
        for(int j =0; j < arr2[0].size(); j++){
            int sum = 0;
            for(int k =0; k < arr1[0].size(); k++){
                int num = arr1[i][k] * arr2[k][j];
                sum += num;
            };
            res.push_back(sum);
        };
        answer.push_back(res);
    }
    return answer;
}

