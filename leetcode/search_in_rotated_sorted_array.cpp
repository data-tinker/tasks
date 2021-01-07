class Solution {
private:
    int findShift(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        if (nums[l] < nums[r]) {
            return 0;
        }

        while (l <= r) {
            int m = (l + r) / 2;
            cout << l << ' ' << r << ' ' << m << endl;

            if (nums[m] > nums[m + 1]) {
                return m + 1;
            }

            if (nums[m] < nums[l]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return 0;
    }

    int searchWithShift(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            return nums[0] == target ? 0 : -1;
        }

        int shift = findShift(nums);
        cout << shift << endl;

        int l = 0;
        int r = nums.size();

        while (l < r) {
            int m = (l + r) / 2;
            int mShifted = m + shift;

            if (mShifted >= nums.size()) {
                mShifted -= nums.size();
            }

            if (nums[mShifted] == target) {
                return mShifted;
            } else if (nums[mShifted] > target) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return -1;
    }

    int searchOnePass(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int m = (l + r) / 2;

            if (nums[m] == target) {
                return m;
            } else if (nums[m] >= nums[l]) {
                if (target >= nums[l] && target < nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                if (target <= nums[r] && target > nums[m]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }

        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        return searchOnePass(nums, target);
    }
};
