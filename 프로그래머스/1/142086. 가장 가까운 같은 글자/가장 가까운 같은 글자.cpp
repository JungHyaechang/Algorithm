#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {

	unordered_map<char, int> lastseek;
	vector<int> answer;
	for (int i = 0; i < s.size(); i++) {
		if (lastseek.find(s[i]) != lastseek.end()) {
			answer.push_back(i - lastseek[s[i]]);
		}
		else {
			answer.push_back(-1);
		}
		lastseek[s[i]] = i;
	}
	return answer;
}

