#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int n = citations.size();

    sort(citations.begin(), citations.end(), greater<int>()); 

    for (int i = 0; i < n; i++) {
        int h = i + 1; 
        if (citations[i] >= h) { 
            answer = h; 
        } else {
            break;
        }
    }

    return answer;
}