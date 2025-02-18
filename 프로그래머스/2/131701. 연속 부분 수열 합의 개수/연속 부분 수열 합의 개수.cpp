#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>

using namespace std;

int solution(vector<int> elements) {
	int answer = 0;
	int n = elements.size();
	vector<int> extended(elements.begin(), elements.end());
	set<int> sumnum;

	extended.insert(extended.end(), elements.begin(), elements.end());

	for (int length = 1; length <= n; length++) {
		for (int start = 0; start < n; start++) {
			sumnum.insert(accumulate(extended.begin() + start, extended.begin() + start + length, 0));
		}
	}
	answer = sumnum.size();
	return answer;
}