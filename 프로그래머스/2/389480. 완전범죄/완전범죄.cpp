#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int sumB = 0;
    for (auto &v : info) sumB += v[1];

    // B가 이미 안전하면 전부 B가 훔쳐도 OK → A 흔적 0이 최솟값
    int need = max(0, sumB - (m - 1));
    if (need == 0) return 0;

    const int INF = 1e9;
    vector<int> dp(need + 1, INF);
    dp[0] = 0;

    for (auto &v : info) {
        int a = v[0], b = v[1];
        // 내려가며 갱신(같은 아이템 중복 사용 방지)
        for (int x = need; x >= 0; --x) {
            if (dp[x] == INF) continue;
            int nx = min(need, x + b);       // need 이상은 포화
            dp[nx] = min(dp[nx], dp[x] + a); // A 비용 누적 최소화
        }
    }

    int best = dp[need];
    return (best < n) ? best : -1;
}
