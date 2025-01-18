#include <string>
#include <vector>
#include <algorithm>

using namespace std;

std::string solution(std::vector<int> food) {

	std::string answer = "";
	for (int i = 1; i < food.size(); i++) {
		if ((food[i] / 2) > 0) {
			for (int j = 0; j < food[i] / 2; j++ ) {
				answer = answer + std::to_string(i);
			}
		}
	}
	
	std::string temp = answer;
	std::reverse(temp.begin(), temp.end());
	
	answer = answer + '0' + temp;
	
	return answer;
}