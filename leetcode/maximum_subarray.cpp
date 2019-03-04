#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(const vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    int result = numeric_limits<int>::min();
    int sum = 0;

    for (auto n: nums) {
        sum = max(n, sum + n);
        result = max(result, sum);
    }

    return result;
}

int main() {
    cout << maxSubArray({-2,1,-3,4,-1,2,1,-5,4}) << endl;

    return 0;
}
