#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
	vector<int> answer;

	int endline = 0;
    int endrow = 0;
	int startline = 51;
    int startrow = 51; // wallpaper.size() <= 50;

	for(int i = 0; i < wallpaper.size(); i++) {
		auto it = wallpaper[i].find('#');
		if (it != string::npos) {
           		if (startline == 51){
                	startline = i;
            		}
			endline = i + 1;
			
			if (startrow >= it) {
				startrow = it;
			}

			for (int j = wallpaper[i].size() - 1; j >= 0; j--) {
				if (wallpaper[i][j] == '#') {
					endrow = max(endrow, j + 1);
					break;
				}
			}
		}
	}

	answer.push_back(startline);
	answer.push_back(startrow);
	answer.push_back(endline);
	answer.push_back(endrow);

	return answer;
}
