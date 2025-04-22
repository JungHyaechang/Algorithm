#include <string>
#include <unordered_map>

using namespace std;

int solution(string word) {
    string vowels = "AEIOU";
    int answer = 0;
    int weight[5] = {781, 156, 31, 6, 1}; 

    for (int i = 0; i < word.length(); ++i) {
        int idx = vowels.find(word[i]); 
        answer += idx * weight[i] + 1;   
    }

    return answer;
}