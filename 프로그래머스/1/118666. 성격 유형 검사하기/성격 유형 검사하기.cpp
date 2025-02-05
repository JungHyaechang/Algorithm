#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
	string answer = "";
	vector<char> ch = { 'R','T','C','F','J','M','A','N' };
	unordered_map<char, int> category;

	// 유형 점수 초기화
	for (char k : ch) {
		category[k] = 0;
	}
	
	// 유형 점수 할당
	for (int i = 0; i < choices.size(); i++) {
		if		(choices[i] == 1) category[survey[i][0]] += 3;
		else if (choices[i] == 2) category[survey[i][0]] += 2;
		else if (choices[i] == 3) category[survey[i][0]] += 1;
		else if (choices[i] == 4) continue;
		else if (choices[i] == 5) category[survey[i][1]] += 1;
		else if (choices[i] == 6) category[survey[i][1]] += 2;
		else if (choices[i] == 7) category[survey[i][1]] += 3;
	}

	if (category['R'] >= category['T']) answer.append("R");
	else  answer.append("T");
	if (category['C'] >= category['F']) answer.append("C");
	else  answer.append("F");
	if (category['J'] >= category['M']) answer.append("J");
	else  answer.append("M");
	if (category['A'] >= category['N']) answer.append("A");
	else  answer.append("N");

	return answer;
}