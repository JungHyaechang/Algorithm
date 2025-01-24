#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<int> section) {
	int answer = 0;

	int i = 0;
	while (i < section.size()) {
		int start = section[i];
		int end = section[i] + m - 1;

		while (i < section.size() && section[i] <= end) {
			i++;
		}
		answer++;
	}
	return answer;
}