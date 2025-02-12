#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
	string answer;
	bool isFisrt = true;

	for (char c : s) {
		if (c == ' ') {
			isFisrt = true;
			answer += c;
		} 
		else {
			if (isFisrt) {
				answer += toupper(c);
				isFisrt = false;
			}
			else
			{
				answer += tolower(c);
			}
		}
	}

	return answer;
}
