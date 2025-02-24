#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    unordered_map<string, int> wantMap;  // 원하는 물품과 개수 저장
    unordered_map<string, int> window;   // 현재 윈도우(10일) 내 물품 개수
    int answer = 0;

    // 원하는 물품과 개수를 해시맵에 저장
    for (int i = 0; i < want.size(); i++) {
        wantMap[want[i]] = number[i];
    }

    // 초기 10일 동안의 상품 개수 기록
    for (int i = 0; i < 10 && i < discount.size(); i++) {
        window[discount[i]]++;
    }

    // 현재 윈도우가 조건을 만족하는지 확인하는 함수
    auto isValid = [&]() {
        for (const auto& [item, count] : wantMap) {
            if (window[item] < count) return false;
        }
        return true;
    };

    // 첫 번째 윈도우가 조건을 만족하는지 확인
    if (isValid()) answer++;

    // 슬라이딩 윈도우 적용
    for (int i = 10; i < discount.size(); i++) {
        // 윈도우에서 빠지는 요소 제거
        window[discount[i - 10]]--;
        if (window[discount[i - 10]] == 0) {
            window.erase(discount[i - 10]); // 필요 없는 요소 정리
        }
        // 새로 들어온 요소 추가
        window[discount[i]]++;

        // 조건을 만족하면 answer 증가
        if (isValid()) answer++;
    }

    return answer;
}