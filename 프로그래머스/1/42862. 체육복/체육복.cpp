#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	
	unordered_map<int, int> umap;

	for (int i = 1; i <= n; i++) {
		umap[i] = 1;
	}

	for (int j = 0; j < lost.size(); j++) {
		umap[lost[j]]--;
	}
	
	for (int k = 0; k < reserve.size(); k++) {
		umap[reserve[k]]++;
	}

	for (int m = 1; m <= n; m++) {
		if (umap[m] == 0) {
			if (m > 1 && umap[m - 1] == 2) {
				umap[m - 1]--;
				umap[m]++;
			}
			else if (m < n && umap[m + 1] == 2) {
				umap[m + 1]--;
				umap[m]++;
			}
		}
		if (umap[m] == 1 || umap[m] == 2) answer++;
	}
	return answer;
}