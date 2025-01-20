#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    	vector<int> answer;
	vector<int> honorlist;
	for (int i = 0; i < score.size(); i++) {
		honorlist.push_back(score[i]);
		sort(honorlist.begin(), honorlist.end(), greater<int>());
		if (honorlist.size() < k) {
			answer.push_back(honorlist[i]);
		}
		else {
			answer.push_back(honorlist[k - 1]);
		}
	}
	return answer;
}