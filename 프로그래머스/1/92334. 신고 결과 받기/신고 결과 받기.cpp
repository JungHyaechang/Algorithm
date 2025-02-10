#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {

	unordered_map<string, unordered_set<string>> reportinglist;
	unordered_map<string, int> reportcount;
	vector<int> answer;

	// 중복 제거, <신고유저, 피신고유저> 파싱 및 피신고유저 신고 횟수 계산
	for (const string& s : report) {
		stringstream ss(s);
		string name;
		string target;
		ss >> name >> target;

		if (reportinglist[name].insert(target).second) {
			reportcount[target]++;
		}
	}

	vector<string> final; // 제외되야할 사람 명단

	for (auto it = reportcount.begin(); it != reportcount.end(); ++it) {
		if (it->second >= k) {
			final.push_back(it->first);
		}
	}

	int reservemail = 0;
	for (const string& s : id_list) {
		int reservemail = 0;
		for (const string& s2 : final) {
			if (reportinglist[s].count(s2) > 0) {
				reservemail++;
			}
		}
		answer.push_back(reservemail);
	}
	return answer;
}