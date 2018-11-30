#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


vector<vector<int>> subsetsHelper(const vector<int>& nums, size_t idx) {
    if (idx == nums.size()) {
        return {{}};
    }

    auto currentSubsets = subsetsHelper(nums, idx + 1);
    auto currentSubsetsSize = currentSubsets.size();

    for (size_t i = 0; i < currentSubsetsSize; ++i) {
        currentSubsets.push_back(currentSubsets[i]);
        currentSubsets.back().push_back(nums[idx]);
    }

    return currentSubsets;
}

vector<vector<int>> subsets(const vector<int>& nums) {
    return subsetsHelper(nums, 0);
}

vector<vector<int>> subsetsIterative(const vector<int>& nums) {
    vector<vector<int>> result;

    for (size_t i = 0; i < 1 << nums.size(); ++i) {
        size_t idx = 0, j = i;
        result.emplace_back();

        while (j) {
            if (j & 1) {
                result.back().push_back(nums[idx]);
            }

            j >>= 1;
            ++idx;
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};

    auto subs = subsetsIterative(nums);

    for (const auto& subset: subs) {
        for (auto el: subset) {
            cout << el << ' ';
        }
        cout << endl;
    }

    return 0;
}
