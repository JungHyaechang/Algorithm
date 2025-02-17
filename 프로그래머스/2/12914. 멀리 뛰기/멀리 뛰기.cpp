#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
	long long answer = 0;

	vector<long long> fibonacci(n + 1);
	fibonacci[0] = 1;
	fibonacci[1] = 2;

	for (int i = 2; i <= n; i++) {
		fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % 1234567;
	}

	answer = fibonacci[n - 1];
    return answer;
}