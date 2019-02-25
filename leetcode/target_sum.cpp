#include <iostream>
#include <vector>

using namespace std;

int findTargetSumWaysHelper(const vector<int>& nums, int s, int idx, int value) {
    if (idx == nums.size()) {
        if (value == s) {
            return 1;
        } else {
            return 0;
        }
    }


    return findTargetSumWaysHelper(nums, s, idx + 1, value + nums[idx]) +
        findTargetSumWaysHelper(nums, s, idx + 1, value - nums[idx]);
}

int findTargetSumWays(const vector<int>& nums, int s) {
    return findTargetSumWaysHelper(nums, s, 0, 0);
}

int main() {
    cout << findTargetSumWays({1, 1, 1, 1, 1}, 3) << endl;

    return 0;
}

