#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int m) {
       vector<int> answer;
    vector<int> a; // n 의 약수
    vector<int> b; // m 의 약수
    vector<int> c; // n 의 배수
    vector<int> d; // m 의 배수

    // n의 약수
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            a.push_back(i);
        }
    }
    // m의 약수
    for (int i = 1; i <= m; i++) {
        if (m % i == 0) {
            b.push_back(i);
        }
    }

    // n,m 의 최대공약수
    int gcd = 1;
    for (int i = b.size()-1; i >= 0; i--) {
        auto it = find(a.begin(), a.end(), b[i]);
        if (it != a.end()) {
            gcd = b[i];
            break;
        }
    }


    // n의 배수
    for (int i = 0; i < m; i++) {
        c.push_back(n * (i + 1));
    }

    // m의 배수
    for (int i = 0; i < n; i++) {
        d.push_back(m * (i + 1));
    }

    int lcm = n * m;
    for (int i = 0; i < d.size(); i++) {
        auto it = find(c.begin(), c.end(), d[i]);
        if (it != c.end()) {
            lcm = d[i];
            break;
        }
    }

    answer = { gcd, lcm };
    
    return answer;
}
