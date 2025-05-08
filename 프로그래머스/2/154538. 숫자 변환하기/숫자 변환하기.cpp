#include <iostream>
#include <queue>
#include <unordered_set>

int solution(int x, int y, int n) {
    if (x == y) return 0;

    std::queue<std::pair<int, int>> q;
    std::unordered_set<int> visited;

    q.push({x, 0});
    visited.insert(x);

    while (!q.empty()) {
        auto [current, steps] = q.front();
        q.pop();

        int candidates[3] = {current + n, current * 2, current * 3};

        for (int next : candidates) {
            if (next == y) {
                return steps + 1;
            }
            if (next < y && visited.find(next) == visited.end()) {
                visited.insert(next);
                q.push({next, steps + 1});
            }
        }
    }

    return -1;
}
