#include <vector>

using namespace std;

int dfs(const vector<int>& numbers, int index, int currentSum, int target) {
    if (index == numbers.size()) {
        return currentSum == target ? 1 : 0;
    }

    int plus = dfs(numbers, index + 1, currentSum + numbers[index], target);
    int minus = dfs(numbers, index + 1, currentSum - numbers[index], target);

    return plus + minus;
}

int solution(vector<int> numbers, int target) {
    return dfs(numbers, 0, 0, target);
}