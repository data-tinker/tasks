/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int l = 0;
        int r = n - 1;
        int peak = -1;

        while (l < r) {
            int m = (l + r) / 2;

            int currentEl = mountainArr.get(m);
            int nextEl = mountainArr.get(m + 1);

            if (currentEl < nextEl) {
                l = peak = m + 1;
            } else {
                r = m;
            }
        }

        l = 0;
        r = peak;

        while (l <= r) {
            int m = (l + r) / 2;

            int currentEl = mountainArr.get(m);

            if (target < currentEl) {
                r = m - 1;
            } else if (target > currentEl) {
                l = m + 1;
            } else {
                return m;
            }
        }

        l = peak;
        r = n - 1;

        while (l <= r) {
            int m = (l + r) / 2;

             int currentEl = mountainArr.get(m);

            if (target > currentEl) {
                r = m - 1;
            } else if (target < currentEl) {
                l = m + 1;
            } else {
                return m;
            }
        }

        return -1;
    }
};
