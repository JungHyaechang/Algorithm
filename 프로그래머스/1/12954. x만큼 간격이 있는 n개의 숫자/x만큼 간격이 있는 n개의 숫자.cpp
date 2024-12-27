#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    
    vector<long long> answer(n);
    
    int sum = x;
    for (int i = 0; i < n; i++) {
        answer[i] = sum;
        sum += x;
    }
    
    return answer;
}