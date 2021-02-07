class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();

        if (arr[0] > arr[1]) {
            return 0;
        } else if (arr[n - 1] > arr[n - 2]) {
            return n - 1;
        }

        int l = 0;
        int r = n;

        while (l < r) {
            int m = (l + r) / 2;
            cout << m << endl;

            if (arr[m - 1] < arr[m] && arr[m] < arr[m + 1]) {
                l = m + 1;
            } else if (arr[m - 1] > arr[m] && arr[m] > arr[m + 1]) {
                r = m;
            } else {
                return m;
            }
        }

        return l;
    }
};
