#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {

	for (char& k : s) {
		if (isupper(k)) {
			k = 'A' + (k - 'A' + n) % 26;}
		else if(islower(k)) {
			k = 'a' + (k - 'a' + n) % 26;}
	}
	return s;
}