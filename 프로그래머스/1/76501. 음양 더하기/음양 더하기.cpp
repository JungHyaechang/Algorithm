#include <string>
#include <vector>

using namespace std;

int solution(vector<int>absolutes, vector<bool>signs) {
	int answer = 0;
	int Size = absolutes.size();
	for (int i = 0; i < Size; i++) {
		if (signs[i] == false) {
			absolutes[i] = (-1) * absolutes[i];
		}
		answer += absolutes[i];
	}
	return answer;
}