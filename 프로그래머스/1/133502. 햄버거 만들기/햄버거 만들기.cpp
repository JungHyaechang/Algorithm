#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
	int answer = 0;

	vector<int> stack;

	for (int i : ingredient) {
		stack.push_back(i);
		if (stack.size() >= 4) {
			int j = stack.size();
			if ((stack[j - 4] == 1) && (stack[j - 3] == 2) && (stack[j - 2] == 3) && (stack[j - 1] == 1)) {
				stack.erase(stack.end() - 4, stack.end());
				answer++;
			}
		}
	}
	
	return answer;
}