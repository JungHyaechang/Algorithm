#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
	string answer = "";
	int day = 0;

	switch (a) {
	case 1: day = b - 1; 
		break;
	case 2: day = 30 + b;
		break;
	case 3: day = 59 + b;
		break;
	case 4:	day = 90 + b;
		break;
	case 5:	day = 120 + b;
		break;
	case 6:	day = 151 + b;
		break;
	case 7: day = 181 + b;
		break;
	case 8: day = 212 + b;
		break;
	case 9: day = 243 + b;
		break;
	case 10: day = 273 + b;
		break;
	case 11: day = 304 + b;
		break;
	case 12: day = 334 + b;
		break;
	}

	int k = day % 7;
	vector<string> weekend = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };
	answer = weekend[k];

	return answer;
}