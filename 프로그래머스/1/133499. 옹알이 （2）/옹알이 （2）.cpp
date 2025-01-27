#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
	int answer = 0;

	vector<string> babylanguage = { "aya", "ye", "woo", "ma" };
	vector<string> replacement = { "000", "00","000","00"};
	size_t pos = 0;
	
	for (int i = 0; i < babbling.size(); i++) {
		bool repeatpattern = false;
		for (size_t k = 0; k < babylanguage.size(); k++) {
			if (babbling[i].find(babylanguage[k] + babylanguage[k]) != string::npos) {
				repeatpattern = true;
				break;
			}
		}
		for (int j = 0; j < babylanguage.size(); j++) {
			pos = 0;
			while ((pos = babbling[i].find(babylanguage[j], pos)) != string::npos) {
				babbling[i].replace(pos, babylanguage[j].length(), replacement[j]);
				pos += replacement[j].length();
			}
		}
		bool allzero = true;
		for (char ch : babbling[i]) {
			if (ch != '0') {
				allzero = false;
				break;
			}
		}
		if (allzero && !repeatpattern) answer++;
	}
	return answer;
}