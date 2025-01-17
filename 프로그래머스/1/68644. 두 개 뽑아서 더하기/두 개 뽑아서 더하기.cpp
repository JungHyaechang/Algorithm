#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> number)
{
	// 2개 뽑아서 합 vector로
	vector<int>answer;

	for (int i = 0; i < number.size() - 1; i++) {
		for (int j = i + 1; j < number.size(); j++) {
			int k = number[i] + number[j];
			auto it = find(answer.begin(), answer.end(), k);
			if (it == answer.end()) {
				answer.push_back(k);
			}
		}
	}

	sort(answer.begin(), answer.end());

	return answer;
}