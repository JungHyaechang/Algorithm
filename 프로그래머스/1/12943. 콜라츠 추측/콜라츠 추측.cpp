#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solution(int a) {
    long long b = a;
  	int answer = 0;

	if (b == 1) {
		return 0;
	}
	
	while (b > 1) {
		if (b % 2 == 0) {
			b = b / 2;
		}
		else {
			b = (b * 3) + 1;
		}
		answer++;
		
		if (answer > 500) {
			return -1;
		}
	}

	return answer;
}