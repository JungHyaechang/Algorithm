#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<int> solution (string today, vector<string> terms, vector<string> privacies) {

	vector<int> answer;
    unordered_map<char, int> termsmap;
    
    for(const string& term : terms) {
    	stringstream ss(term);
        char type;
        int months;
        ss >> type >> months; // 공백을 기준으로 분리, string -> char, int 자동변환
        termsmap[type] = months;
    }
	
    // today를 연, 월, 일로 변환 (int형)
    int TodayYear = stoi(today.substr(0, 4));
    int TodayMonth = stoi(today.substr(5, 2));
    int TodayDay = stoi(today.substr(8, 2));
    
    for (int i = 0; i < privacies.size(); i++) {
    	char type = privacies[i][11];
        
        // privacies를 연, 월, 일로 변환 (int형)
        int Year = stoi(privacies[i].substr(0, 4));
        int Month = stoi(privacies[i].substr(5, 2));
        int Day = stoi(privacies[i].substr(8, 2));
    	
        // 유효기간 추가
        Month += termsmap[type];
        
        // 12개월 초과하면 연도 증가
        while (Month > 12) {
        	Year += 1;
            Month -= 12;
        }

		// 날짜 조정 (유효기간이 끝나는 날짜는 "해당 날짜 -1")
        Day -= 1;
        if (Day == 0) {
        	Month -= 1;
            if (Month == 0) {
            Month = 12;
            Year -= 1;
            }
            Day = 28;
        }
        
       if ((Year < TodayYear) ||
        	((Year == TodayYear) && (Month < TodayMonth)) ||
            ((Year == TodayYear) && (Month == TodayMonth) && (Day < TodayDay))) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}