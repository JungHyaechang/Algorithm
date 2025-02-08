#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {

	unordered_map<string, int> PlayerIndex;

	for (int i = 0; i < players.size(); i++) {
		PlayerIndex[players[i]] = i;
	}

	for (const string& name : callings) {
		int index = PlayerIndex[name];

		if (index > 0) {
			swap(players[index], players[index - 1]);

			PlayerIndex[players[index]] = index;
			PlayerIndex[players[index - 1]] = index - 1;
		}
	}

	return players;
}