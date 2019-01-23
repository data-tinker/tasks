#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size();
    int m;

    while (l < r) {
        m = (l + r) / 2;

        if (nums[m] == target) {
            return m;
        } else if (nums[m] < target) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    return l;
}

int main() {
    vector<int> v{1,3,5,6};
    int target = 0;

    cout << searchInsert(v, target) << endl;

    return 0;
}
