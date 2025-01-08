#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {

	vector<int> w;
	vector<int> h;
	int temp = 0;
	for (auto& row : sizes) {
		if (row[0] < row[1]) {
			temp = row[0];
			row[0] = row[1];
			row[1] = temp;
		}

		w.push_back(row[0]);
		h.push_back(row[1]);
	}

	sort(w.begin(), w.end(), greater<int>());
	sort(h.begin(), h.end(), greater<int>());

	int answer = w[0] * h[0];

	return answer;
}