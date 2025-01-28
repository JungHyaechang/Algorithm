#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
	vector<int> countX(10, 0), countY(10, 0);

	for (char a : X) {
		countX[a - '0']++;
	}
	for (char b : Y) {
		countY[b - '0']++;
	}

	string answer = "";

	for (int i = 9; i >= 0; i--) {
		int samecount = min(countX[i], countY[i]);
		answer.append(samecount, i + '0');
	}

	if (answer == "") {
		return "-1";
	}
	else if (answer[0] == '0') {
		return "0";
	}
	else return answer;
}