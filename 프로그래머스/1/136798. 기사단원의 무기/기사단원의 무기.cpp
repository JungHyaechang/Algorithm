#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int num, int limit, int power) {
	int answer = 0;

	int count = 0;
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= sqrt(i); j++) {
			if (i % j == 0) {
				if (j == i / j) {
					count++;
				}
				else {
					count += 2;
				}
			}
		}
		if (count > limit) {
			count = power;
		}
		answer += count;
		count = 0;
	}

	return answer;
}