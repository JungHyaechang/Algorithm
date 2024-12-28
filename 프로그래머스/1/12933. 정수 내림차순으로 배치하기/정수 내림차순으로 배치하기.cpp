#include <string>
#include <vector>
#include <iostream>
using namespace std;

void bubblesort(vector<int> &V) {
    int m = V.size();
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < m - i; j++) {
            if (V[j] < V[j + 1]) {
                int temp = V[j];
                V[j] = V[j + 1];
                V[j + 1] = temp;
            }
        }
    }
}

long long solution(long long n) {
    long long answer = 0;
    vector<int> v;

    do {
        v.push_back(n % 10);
        n = n / 10;
    } while (n > 0);
    
    bubblesort(v);

    for (int i = 0; i < v.size(); i++) {
        answer = answer * 10 + v[i];
    }
    return answer;
}
