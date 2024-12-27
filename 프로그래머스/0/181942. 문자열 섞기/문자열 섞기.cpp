#include <iostream>
#include <string>

using namespace std;

string solution(string str1, string str2) {
	string answer;
	int n = max(str1.size(), str2.size());

	for (int i = 0; i < n; i++) {
		if (i < str1.size()) answer += str1[i];
		if (i < str2.size()) answer += str2[i];
	}
	cout << answer << endl;
	
	return answer;
}