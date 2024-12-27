#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string str = to_string(n);
    int k = str.size();

    for (int i = k-1  ; i >= 0; i--) {
        answer.push_back(str[i] - '0');
    }
    return answer;
}