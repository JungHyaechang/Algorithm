#include <iostream>
#include <vector>
#include <cmath>

int solution(int n) {

	std::vector<int> vec3;
	int answer= 0;

	while (n != 0) {
		vec3.push_back(n % 3);
		n = n / 3;
	}

	int count = 0;
	for (auto it = vec3.rbegin(); it != vec3.rend(); it++) {
		answer += *it * pow(3, count);
		count++;
	}

	return answer;
}