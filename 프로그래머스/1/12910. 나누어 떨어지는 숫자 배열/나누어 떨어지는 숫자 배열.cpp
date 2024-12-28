#include <string>
#include <vector>

using namespace std;

void SelectionSort(vector<int>& arr) {
	for (int i = 0; i < arr.size() - 1; i++) {
		int minIdx = i;
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[minIdx] > arr[j]) {
				minIdx = j;
			}
		}
		if (minIdx != i) {
			int temp = arr[minIdx];
			arr[minIdx] = arr[i];
			arr[i] = temp;
		}
	}
}

vector<int> solution(vector<int> array, int divisor) {

	vector<int> answer;

	for (int i = 0; i < array.size(); i++) {
		if (array[i] % divisor == 0) {
			answer.push_back(array[i]);
		} 
	}
 	if (answer.size() == 0) {
		answer.push_back(-1);
	}
    	SelectionSort(answer);
		
	return answer;
}
