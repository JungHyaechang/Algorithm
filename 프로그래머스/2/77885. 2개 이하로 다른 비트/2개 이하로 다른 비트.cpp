#include <vector>
#include <string>
#include <bitset>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (long long x : numbers) {
        if (x % 2 == 0) {
          
            answer.push_back(x + 1);
        } else {
            long long bit = 1;
            while ((x & bit) != 0) {
                bit <<= 1;
            }
            long long next = x + bit - (bit >> 1);
            answer.push_back(next);
        }
    }

    return answer;
}