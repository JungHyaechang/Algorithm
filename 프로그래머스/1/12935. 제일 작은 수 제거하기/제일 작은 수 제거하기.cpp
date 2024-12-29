#include <string>
#include <vector>
using namespace std;

vector<int> solution (vector<int> arr) {
	
		int minIdx = 0;
	if (arr.size() == 1) {
		arr.erase(arr.begin());
		arr.push_back(-1);
	}
	else {
		for (int i = 0; i < arr.size(); i++) {
			if (arr[minIdx] > arr[i]) {
				minIdx = i;
			}
		}
		arr.erase(arr.begin() + minIdx);
	}
	vector<int> answer = arr;

	return answer;
}