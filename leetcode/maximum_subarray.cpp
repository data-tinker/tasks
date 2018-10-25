#include <iostream>
#include <vector>

using namespace std;

int maximumSubarray(const vector<int>& nums) {
    size_t it = 0;

    int result = *max_element(begin(nums), end(nums));
    int sum = 0;

    while (it < nums.size()) {
        sum += nums[it++];

        if (sum >= 0) {
            result = max(sum, result);
        } else {
            sum = 0;
        }
    }

    return result;
}

int main() {
    vector<int> nums{-1};

    cout << maximumSubarray(nums) << endl;

    return 0;
}
