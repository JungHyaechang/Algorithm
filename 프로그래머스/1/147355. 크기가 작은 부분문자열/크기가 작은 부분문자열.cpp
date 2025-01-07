#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    vector<string> y;
    string k;
    int count = 0;
    for (int i = 0; i <= t.size()-p.size(); i++) {
        k = {};
        for (int j = i; j < i + p.size(); j++) {
            k += t[j];
        }
        y.push_back(k);
    }
    
    for (int i = 0; i < y.size(); i++) {
        long long number = stoll(y[i]);
        long long number1 = stoll(p);

        if (number <= number1) {
            answer++;
        }
    }
    return answer;
}