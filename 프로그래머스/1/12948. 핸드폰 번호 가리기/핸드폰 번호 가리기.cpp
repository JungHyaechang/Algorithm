#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    
    size_t ReplaceLength = phone_number.size() - 4;
    char asterisk = '*';
        
    string ReplaceString(ReplaceLength, asterisk);
    phone_number.replace(0, ReplaceLength, ReplaceString);
    
    return phone_number;
}