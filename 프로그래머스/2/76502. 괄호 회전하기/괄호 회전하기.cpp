#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool correctpair(const string& s) {
	stack<char> stk;

	for (char c : s) {
		if (c == '(' || c == '{' || c == '[') {
			stk.push(c);
		}
		else {
			if (stk.empty()) return false;
			char top = stk.top();
			if ((c == ')') && (top == '(') ||
				(c == '}') && (top == '{') ||
				(c == ']') && (top == '['))
			{
				stk.pop();
			}
			else return false;
		}
	}

	return stk.empty();
}

int solution(string s) {
	int answer = 0;
	int x = s.size();

	for (int i = 0; i < x; i++) {
		if (correctpair(s)) {
			answer++;
		}
		rotate(s.begin(), s.begin() + 1, s.end());
	}
	return answer;
}