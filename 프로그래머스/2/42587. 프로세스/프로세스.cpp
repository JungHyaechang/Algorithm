#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;  
    vector<int> sorted_priorities = priorities;  
    
    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
    }
    
    sort(sorted_priorities.rbegin(), sorted_priorities.rend());
    
    int answer = 0; 
    int index = 0;  

    while (!q.empty()) {
        int priority = q.front().first;
        int idx = q.front().second;
        q.pop();

        if (priority == sorted_priorities[index]) {
            answer++;
            index++;  

            if (idx == location) return answer;
        } 
        else {
            q.push({priority, idx});
        }
    }
}