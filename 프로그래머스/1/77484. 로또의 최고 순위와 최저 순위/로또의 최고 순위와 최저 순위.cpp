#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer;
	int maxnum;
	int minnum;
	int correctcount = 0;
	int zerocount = 0;

	for (int i = 0; i < win_nums.size(); i++) {
		auto it = find(lottos.begin(), lottos.end(), win_nums[i]);
		if (it != lottos.end()) {
			correctcount++;
		}
	}

	for (int i = 0; i < lottos.size(); i++) {
		if (lottos[i] == 0) zerocount++;
	}
	
	if ((correctcount + zerocount) == 0 || (correctcount + zerocount) == 1) maxnum = 6;
	else if ((correctcount + zerocount) == 2) maxnum = 5;
	else if ((correctcount + zerocount) == 3) maxnum = 4;
	else if ((correctcount + zerocount) == 4) maxnum = 3;
	else if ((correctcount + zerocount) == 5) maxnum = 2;
	else if ((correctcount + zerocount) == 6) maxnum = 1;

	if (correctcount == 0 || correctcount == 1) minnum = 6;
	else if (correctcount == 2) minnum = 5;
	else if (correctcount == 3) minnum = 4;
	else if (correctcount == 4) minnum = 3;
	else if (correctcount == 5) minnum = 2;
	else if (correctcount == 6) minnum = 1;

	return answer = { maxnum, minnum };
}