#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
	int answer = 0;
	unordered_map<int, int> size_num;

	for (int i : tangerine) {
		size_num[i]++;
	}

	vector<pair<int, int>> sorted_sizenum(size_num.begin(), size_num.end());
	sort(sorted_sizenum.begin(), sorted_sizenum.end(),
		[](const pair<int, int>& a, const pair<int, int>& b)
		{return a.second > b.second;});

	int numbering = 0;
	for (int i = 0; i < sorted_sizenum.size(); i++) {
		numbering += sorted_sizenum[i].second;
		answer++;
		if (numbering >= k) break;
	}
	return answer;
}