#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
	int DeleteZeroCount = 0;
	int TryBinary = 0;
	vector<int> answer;

	do {
		// 0 제거
		string OnlyNum1 = "";
		for (char iszero : s) {
			if (iszero == '1') {
				OnlyNum1.push_back(iszero);
			}
			else DeleteZeroCount++; // 0제거 횟수 추가
		}

		int distance = OnlyNum1.size();
		vector<int> binary(0);

		// 2진법 변환
		while (distance != 0) {
			binary.push_back(distance % 2);
			distance = distance / 2;
		}

		TryBinary++; // 2진변환 횟수 추가
		s = "";
		for (char ch : binary) {
			s += ch + '0';
		}
	} while (s != "1");

	answer = { TryBinary, DeleteZeroCount };
	return answer;
}