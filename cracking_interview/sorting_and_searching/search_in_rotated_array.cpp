#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size();

    while (l < r) {
        int m = (l + r) / 2;

        if (nums[m] == target) {
            return m;
        } else if (nums[l] <= nums[m]) {
            if (target > nums[m]) {
                l = m + 1;
            } else if (target >= nums[l]) {
                r = m;
            } else {
                l = m + 1;
            }
        } else if (target < nums[m]) {
            r = m;
        } else if (target <= nums[r - 1]) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    return -1;
}

int main() {
    vector<int> nums{3, 1};

    cout << search(nums, 3) << endl;

    return 0;
}
