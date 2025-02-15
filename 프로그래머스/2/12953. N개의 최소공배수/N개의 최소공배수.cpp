#include <string>
#include <vector>

using namespace std;

int lcm(int x, int y) {
	int a = x;
	int b = y;
	while (y != 0) {
		int temp = y;
		y = x % y;
		x = temp;
	}
	int gcd = x;
	return (a / gcd) * b;
}

int solution(vector<int> arr) {
	int answer = arr[0];

	for (size_t i = 1; i < arr.size(); ++i) {
		answer = lcm(answer, arr[i]);
	}
	return answer;
}