#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
	vector<int> answer;

	for (const string& target : targets) {
		int sum = 0;
		bool isValid = true; // 모든 문자가 존재하는지 확인

		for (char ch : target) {
			int idxcount = -1; // 각 문자별 최소 인덱스 저장

			for (const string& key : keymap) {
				size_t it = key.find(ch);
				if (it != string::npos) {
					if (idxcount == -1 || it < idxcount) {
						idxcount = it;
					}
				}
			}

			if (idxcount == -1) { // 문자를 찾지 못한 경우
				isValid = false;
				break;
			}

			sum += (idxcount + 1); // 1-based index로 변환하여 더함
		}

		answer.push_back(isValid ? sum : -1);
	}

	return answer;
}