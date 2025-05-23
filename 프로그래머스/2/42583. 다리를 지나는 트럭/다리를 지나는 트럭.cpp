#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge;              
    int time = 0;                   
    int total_weight = 0;          
    int index = 0;                 

    for (int i = 0; i < bridge_length; ++i) {
        bridge.push(0);
    }

    while (!bridge.empty()) {
        time++;

        total_weight -= bridge.front();
        bridge.pop();

        if (index < truck_weights.size()) {
            int next_truck = truck_weights[index];

            if (total_weight + next_truck <= weight) {
                bridge.push(next_truck);
                total_weight += next_truck;
                index++;
            } else {
                bridge.push(0); 
            }
        }
    }

    return time;
}
