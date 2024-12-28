#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
	long long answer = 0;
	int* v = new int[a - b + 1];

	if (a > b) {
		for (int i = 0; i < (a - b) + 1; i++) {
			v[i] = b + i;
			answer += v[i];
		}
	}
	else if (a < b) {
		for (int i = 0; i < (b - a) + 1; i++) {
			v[i] = a + i;
			answer += v[i];
		}
	}
	else {
		answer = a;
	}
	return answer;
}