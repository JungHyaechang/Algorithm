#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
	string answer = "";

	vector<char> alphabet;

	for (char c = 'a'; c <= 'z'; c++) {
		alphabet.push_back(c);
	}

	for (int j = 0; j < skip.size(); j++) {
		alphabet.erase(remove_if(alphabet.begin(), alphabet.end(), [&](char c) {return skip.find(c) != string::npos;}), alphabet.end());
	}

	for (char& c : s) {
		auto it = find(alphabet.begin(), alphabet.end(), c);
		if (it != alphabet.end()) {
			int pos = distance(alphabet.begin(), it);
			int newpos = (pos + index) % alphabet.size();
			c = alphabet[newpos];
		} 
	}
	return s;
}