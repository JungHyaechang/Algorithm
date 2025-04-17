#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <sstream>
#include <iomanip>
using namespace std;

int timeToMinutes(const string& timeStr) {
    int hours = stoi(timeStr.substr(0, 2));
    int minutes = stoi(timeStr.substr(3, 2));
    return hours * 60 + minutes;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    int basicTime = fees[0], basicFee = fees[1];
    int unitTime = fees[2], unitFee = fees[3];
    
    map<string, int> inTime;           
    map<string, int> totalTime;        

    for (const string& record : records) {
        stringstream ss(record);
        string timeStr, carNum, action;
        ss >> timeStr >> carNum >> action;

        int time = timeToMinutes(timeStr);

        if (action == "IN") {
            inTime[carNum] = time;
        } else if (action == "OUT") {
            int duration = time - inTime[carNum];
            totalTime[carNum] += duration;
            inTime.erase(carNum);
        }
    }

  
    for (const auto& entry : inTime) {
        string carNum = entry.first;
        int duration = timeToMinutes("23:59") - entry.second;
        totalTime[carNum] += duration;
    }

    vector<int> result;
    for (const auto& entry : totalTime) {
        int time = entry.second;
        int fee = basicFee;
        if (time > basicTime) {
            fee += ceil((time - basicTime) / (double)unitTime) * unitFee;
        }
        result.push_back(fee);
    }

    return result;
}