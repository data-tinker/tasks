#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numsOccurances;

    for (int i = 0; i < nums.size(); ++i) {
        auto complement = target - nums[i];

        if (numsOccurances.find(complement) != numsOccurances.end()) {
            return {numsOccurances[complement], i};
        }

        numsOccurances[nums[i]] = i;
    }

    return {-1, -1};
}

vector<int> twoSumIterators(vector<int>& nums, int target) {
        vector<pair<int, int>> numsWithIndices;

        for (int i = 0; i < nums.size(); ++i) {
            numsWithIndices.emplace_back(nums[i], i);
        }

        sort(begin(numsWithIndices), end(numsWithIndices));

        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int sum = numsWithIndices[l].first + numsWithIndices[r].first;

            if (sum == target) {
                return {numsWithIndices[l].second, numsWithIndices[r].second};
            } else if (sum < target) {
                ++l;
            } else {
                --r;
            }
        }

        return {-1, -1};
    }

int main() {
    vector<int> v{3, 2, 4};

    auto pos = twoSum(v, 6);

    cout << pos[0] << ' ' << pos[1] << endl;

    return 0;
}
