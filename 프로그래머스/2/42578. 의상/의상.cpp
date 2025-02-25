#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;

	unordered_map<int, vector<string>> wardrove;
	unordered_map<string, int> categoryToInt;
	int CategoryIndex = 1;

	for (const vector<string>& strvec : clothes)
	{
		string category = strvec[1];

		if (categoryToInt.find(category) == categoryToInt.end())
		{
			categoryToInt[category] = CategoryIndex++;
		}

		int categorykey = categoryToInt[category];
		wardrove[categorykey].push_back(strvec[0]);
	}

	for (const auto& pair : wardrove) {
		answer *= (pair.second.size() + 1);
	}

	return answer - 1;
}