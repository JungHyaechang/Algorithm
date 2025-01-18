#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {

    int answer = 0;
    int remainsum = 0;
    while (n >= a) {
        remainsum = n % a;
        int exchange = (n / a) * b;
        answer += exchange;
        n = exchange + remainsum;
        remainsum = 0;
    }
    return answer;
}
