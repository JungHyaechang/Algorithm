#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	vector<int> divisor;

	for (int i = 1; i <= sqrt(yellow); i++) {
		if (yellow % i == 0) {
			int yellow_width = i;
			int yellow_length = yellow / i;

			int total_width = yellow_width + 2;
			int total_length = yellow_length + 2;

			if ((total_length * total_width) - yellow == brown) {
				answer.push_back(max(total_length, total_width));
				answer.push_back(min(total_length, total_width));
			}
		}
	}
	return answer;
}