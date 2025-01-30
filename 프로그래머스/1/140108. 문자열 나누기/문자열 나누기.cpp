#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;
	int samecount = 0;
	int diffcount = 0;
	for (int i = 0; i < s.size(); i++) {
		
		if (s[i] == s[0]) { samecount++; }
		else { diffcount++; }

		int idxcount = samecount + diffcount;
		if ((samecount == diffcount) || (idxcount == s.length())) {
			s.erase(s.begin(), s.begin() + idxcount);
			answer++;
			samecount = 0;
			diffcount = 0;
			i = -1;
		} 
	}
	return answer;
}
