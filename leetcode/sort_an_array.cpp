class SortingAlgorithm {
public:
    virtual vector<int> sort(vector<int>& nums) = 0;
};

class QuickSort : public SortingAlgorithm {
private:
    int partition(vector<int>& nums, int l, int r, int pivotIdx) {
        swap(nums[l], nums[pivotIdx]);
        int newPivotIdx = l;

        for (size_t i = l + 1; i < r; ++i) {
            if (nums[i] <= nums[l]) {
                swap(nums[i], nums[++newPivotIdx]);
            }
        }

        swap(nums[l], nums[newPivotIdx]);

        return newPivotIdx;
    }

    void sort(vector<int>& nums, int l, int r) {
        if (l < r) {
            int pivotIdx = (l + r) / 2;
            pivotIdx = partition(nums, l, r, pivotIdx);

            sort(nums, l, pivotIdx);
            sort(nums, pivotIdx + 1, r);
        }
    }
public:
    vector<int> sort(vector<int>& nums) {
        sort(nums, 0, nums.size());

        return nums;
    }
};

class MergeSort : public SortingAlgorithm {
private:
    void merge(vector<int>& nums, int l, int m, int r) {
        vector<int> leftSubarray;
        vector<int> rightSubarray;

        for (size_t i = l; i <= r; ++i) {
            if (i <= m) {
                leftSubarray.push_back(nums[i]);
            } else {
                rightSubarray.push_back(nums[i]);
            }
        }

        int leftPointer = 0;
        int rightPointer = 0;

        while (leftPointer < leftSubarray.size() && rightPointer < rightSubarray.size()) {
            if (leftSubarray[leftPointer] <= rightSubarray[rightPointer]) {
                nums[l++] = leftSubarray[leftPointer++];
            } else {
                nums[l++] = rightSubarray[rightPointer++];
            }
        }

        for (size_t i = leftPointer; i < leftSubarray.size(); ++i) {
            nums[l++] = leftSubarray[i];
        }

        for (size_t i = rightPointer; i < rightSubarray.size(); ++i) {
            nums[l++] = rightSubarray[i];
        }
    }

    void sort(vector<int>& nums, int l, int r) {
        if (l < r) {
            int m = (l + r) / 2;

            sort(nums, l, m);
            sort(nums, m + 1, r);
            merge(nums, l, m, r);
        }
    }
public:
    vector<int> sort(vector<int>& nums) {
        sort(nums, 0, nums.size() - 1);

        return nums;
    }
};

class Solution {
private:
    unique_ptr<SortingAlgorithm> algorithm;
public:
    Solution() {
        algorithm = make_unique<QuickSort>();
    }

    vector<int> sortArray(vector<int>& nums) {
        algorithm->sort(nums);

        return nums;
    }
};
