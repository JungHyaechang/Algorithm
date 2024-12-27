#include <iostream>
#include <string>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
	
    string result = my_string.substr(0, s);
	
    result += overwrite_string;
    
    result += my_string.substr(overwrite_string.size()+s);
    
    return result;
}


