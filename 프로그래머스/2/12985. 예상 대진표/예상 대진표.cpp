#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
	int answer = 1;
	
	while (n == 1) {
		int i = min(a, b);
		int j = max(a, b);

		if ((i == j - 1) && ((i / 2) != (j / 2))) {
			return answer;
		}
		else {
			if (a % 2 == 1) {
				a = (a + 1) / 2;
			}
			else a /= 2;

			if (b % 2 == 1) {
				b = (b + 1) / 2;
			}
			else b /= 2;

			n /= 2;
			answer++;
		}
	}
}