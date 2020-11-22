class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size(), nums.size() - k);
    }

    int quickSelect(vector<int> &v, int l, int r, int k) {
        if (l < r) {
            int pivot = (l + r) / 2;
            int p = partition(v, l, r, pivot);

            if (p == k)
                return v[k];
            else if (k < p)
                return quickSelect(v, l, p, k);
            else
                return quickSelect(v, p + 1, r, k);
        } else {
            return v[l];
        }
    }

    int partition(vector<int> &v, int l, int r, int pivot) {
        swap(v[pivot], v[l]);
        int p = l;

        for (size_t i = l + 1; i < r; ++i) {
            if (v[i] <= v[l]) {
                ++p;
                swap(v[i], v[p]);
            }
        }
        swap(v[l], v[p]);

        return p;
    }

};
