#include <iostream>
#include <string>
#include <cctype>

std::string solution(std::string s) {
	
	int index = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			index = 0;
		}
		else {
			if (index % 2 == 0) {
				s[i] = std::toupper(s[i]);
			}
			else {
				s[i] = std::tolower(s[i]);
			}
			index++;
		}
		
	}
	return s;
}