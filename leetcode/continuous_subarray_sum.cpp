class Solution {
private:
    bool checkSubarraySumMap(vector<int>& nums, int k) {
        unordered_map<int, int> sumsToIdx;
        k = abs(k);

        int sum  = 0;
        sumsToIdx[0] = -1;

        for (size_t i = 0; i < nums.size(); ++i) {
            sum += nums[i];

            if (k != 0) {
                sum %= k;
            }

            auto found = sumsToIdx.find(sum);
            if (found != sumsToIdx.end()) {
                if (i - found->second > 1) {
                    return true;
                }
            } else {
                sumsToIdx[sum] = i;
            }
        }

        return false;
    }

    bool checkSubarraySumPrefix(const vector<int>& nums, int k) {
        vector<int> prefixSums{0};

        int currentSum = 0;

        for (auto n : nums) {
            currentSum += n;
            prefixSums.push_back(currentSum);
        }

        for (size_t i = 0; i <= nums.size(); ++i) {
            for (size_t j = i + 2; j <= nums.size(); ++j) {
                currentSum = prefixSums[j] - prefixSums[i];

                if (k != 0 && currentSum >= k && currentSum % k == 0) {
                    return true;
                } else if (currentSum == 0) {
                    return true;
                }
            }
        }

        return false;
    }
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        return checkSubarraySumMap(nums, k);
    }
};
