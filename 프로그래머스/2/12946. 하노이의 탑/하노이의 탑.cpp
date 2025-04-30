#include <vector>
#include <iostream>
using namespace std;

void MoveDisks(int n, int from, int via, int to, vector<vector<int>>& answer) {
    if (n == 1) {
        answer.push_back({from, to});
        return;
    }
    MoveDisks(n - 1, from, to, via, answer);
    answer.push_back({from, to});           
    MoveDisks(n - 1, via, from, to, answer);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    MoveDisks(n, 1, 2, 3, answer); 
    return answer;
}
