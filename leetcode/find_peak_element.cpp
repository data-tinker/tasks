#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
    size_t n = nums.size();

    if (n == 0) {
        return -1;
    } else if (n == 1){
        return 0;
    }

    if (nums[0] > nums[1]) {
        return 0;
    }

    if (nums[n - 1] > nums[n - 2]) {
        return n - 1;
    }

    int l = 0;
    int r = n;

    while (l < r) {
        int m = (l + r) / 2;

        if (nums[m] > nums[m - 1] && nums[m] > nums[m + 1]) {
            return m;
        } else if (nums[m] < nums[m - 1]) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    return -1;
}

int main() {
    vector<int> nums{1,3,2,1};

    cout << findPeakElement(nums) << endl;

    return 0;
}
