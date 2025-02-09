#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {

	int Wide = 0;
	int Height = 0;
	bool shouldbreak = false;

	// 스타트 지점 찾기
	for (int i = 0; i < park.size(); i++) {
		for (int j = 0; j < park[i].size(); j++) {
			if (park[i][j] == 'S') {
				Height = i;
				Wide = j;
				shouldbreak = true;
				break;
			}
		}
		if (shouldbreak) break;
	}

	vector<int> StartCoordinate = { Height, Wide };

	for (int i = 0; i < routes.size(); i++) {
		int distance = stoi(routes[i].substr(2));
		char direction = routes[i][0];

		if ((direction == 'E') && (distance + Wide < park[Height].size())) {
			bool canMove = true;
			for (int i = Wide + 1; i <= Wide + distance; i++) {
				if (park[Height][i] == 'X') {
					canMove = false;
					break;
				}
			}
			if (canMove) {
				Wide += distance;
			}
		}

		else if ((direction == 'W') && (Wide - distance >= 0)) {
			bool canMove = true;
			for (int i = Wide - 1; i >= Wide - distance; i--) {
				if (park[Height][i] == 'X') {
					canMove = false;
					break;
				}
			}
			if (canMove) {
				Wide -= distance;
			}
		}

		else if ((direction == 'N') && (Height - distance >= 0)) {
			bool canMove = true;
			// 현재 위치 바로 위부터 도착 위치까지 확인
			for (int j = Height - 1; j >= Height - distance; j--) {
				if (park[j][Wide] == 'X') {
					canMove = false;
					break;
				}
			}
			if (canMove) {
				Height -= distance;
			}
		}

		else if ((direction == 'S') && (Height + distance < park.size())) {
			bool canMove = true;
			// 현재 위치 바로 아래부터 도착 위치까지 확인
			for (int j = Height + 1; j <= Height + distance; j++) {
				if (park[j][Wide] == 'X') {
					canMove = false;
					break;
				}
			}
			if (canMove) {
				Height += distance;
			}
		}
	}

	vector<int> answer = { Height, Wide };

	return answer;
}