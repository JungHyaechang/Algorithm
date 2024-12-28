#include <string>
#include <iostream>


using namespace std;

int solution(string s) {

    int a;
    a = s.size();
    int answer = 0;
    
    switch (s[0]) {
    case '-':
        for (int i = 1; i < a; i++) {
            answer = answer*10 + (s[i] - '0');
        }
        answer = ( - 1) * answer;
        break;
    case '+':
        for (int i = 1; i < a; i++) {
            answer = answer * 10 + (s[i] - '0');
        }
        break;
    default:
        for (int i = 0; i < a; i++) {
            answer = answer * 10 + (s[i] - '0');
        }
        break;
    }
    return answer;
}