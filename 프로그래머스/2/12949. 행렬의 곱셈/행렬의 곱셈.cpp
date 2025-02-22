#include <string>
#include <vector>

using namespace std;

int elementCalculate(const vector<int>& a, const vector<int>& b) {
    int answer = 0;
    for (size_t i = 0; i < a.size(); i++) {
        answer += a[i] * b[i];
    }
    return answer;
}

vector<vector<int>> makeColumn(const vector<vector<int>>& arr) {
    vector<vector<int>> column(arr[0].size()); 

    for (size_t i = 0; i < arr[0].size(); i++) {
        for (size_t j = 0; j < arr.size(); j++) {
            column[i].push_back(arr[j][i]); 
        }
    }
    return column;
}

vector<vector<int>> matrixMultiplier(const vector<vector<int>>& arr1, const vector<vector<int>>& arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2.size(), 0));

    for (size_t i = 0; i < arr1.size(); i++) {
        for (size_t j = 0; j < arr2.size(); j++) {
            answer[i][j] = elementCalculate(arr1[i], arr2[j]);
        }
    }
    return answer;
}

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> transformedArr2 = makeColumn(arr2);  
    return matrixMultiplier(arr1, transformedArr2);
}