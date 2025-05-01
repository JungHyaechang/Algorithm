#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int n = topping.size();
    unordered_map<int, int> leftCount, rightCount;
    vector<int> leftUnique(n), rightUnique(n);

    for (int i = 0; i < n; ++i)
        rightCount[topping[i]]++;

    int leftKinds = 0, rightKinds = rightCount.size();
    int fairCuts = 0;

    for (int i = 0; i < n - 1; ++i) {
        int top = topping[i];

        if (++leftCount[top] == 1)
            leftKinds++;

        if (--rightCount[top] == 0)
            rightKinds--;

        if (leftKinds == rightKinds)
            fairCuts++;
    }

    return fairCuts;
}
