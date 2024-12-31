#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    
    bool answer = 1;
    
    if(s.size() != 4 && s.size() != 6) {
        return 0;
    }
    
    for(int i = 0; i < s.size(); i++){
        if(isdigit(s[i]) == 0){
            answer = 0;
            break;
        } 
    }
    
    return answer;
}
    
    
    