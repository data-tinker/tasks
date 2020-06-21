#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return {};
        }

        vector<vector<int>> result;

        sort(begin(nums), end(nums));

        for (size_t firstIdx = 0; firstIdx < nums.size() - 2; ++firstIdx) {
            if (firstIdx > 0 && nums[firstIdx] == nums[firstIdx - 1]) {
                continue;
            }

            size_t secondIdx = firstIdx + 1;
            size_t thirdIdx = nums.size() - 1;

            int requiredSum = 0 - nums[firstIdx];

            while (secondIdx < thirdIdx) {
                int currentSum = nums[secondIdx] + nums[thirdIdx];

                if (currentSum < requiredSum) {
                    ++secondIdx;
                } else if (currentSum > requiredSum) {
                    --thirdIdx;
                } else {
                    result.push_back(vector<int>{nums[firstIdx], nums[secondIdx], nums[thirdIdx]});
                    ++secondIdx;
                    while (secondIdx < thirdIdx && nums[secondIdx] == nums[secondIdx - 1]) {
                        ++secondIdx;
                    }
                }
            }
        }

        return result;
    }
};


int main() {
    vector<int> nums{-3, -3, 6};

    auto result = Solution().threeSum(nums);

    for (const auto& row: result) {
        for (const auto& el: row) {
            cout << el << ' ';
        }
        cout << endl;
    }

    return 0;
}
