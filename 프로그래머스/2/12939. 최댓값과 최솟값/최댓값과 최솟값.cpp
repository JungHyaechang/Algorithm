#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
	string answer = "";
	vector<int> array;

	stringstream ss(s);
	string ch;
	while (ss >> ch) array.push_back(stoi(ch));

	sort(array.begin(), array.end());

	answer.append(to_string(array[0]));
	answer.append(" ");
	answer.append(to_string(array[array.size() - 1]));

	return answer;
}