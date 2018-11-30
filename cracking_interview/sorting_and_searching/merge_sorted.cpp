#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int l = m - 1;
    int r = n - 1;
    int i = nums1.size() - 1;

    while (l >= 0 && r >= 0) {
        if (nums1[l] >= nums2[r]) {
            nums1[i--] = nums1[l--];
        } else {
            nums1[i--] = nums2[r--];
        }
    }

    while (l >= 0) {
        nums1[i--] = nums1[l--];
    }

    while (r >= 0) {
        nums1[i--] = nums2[r--];
    }
}

int main() {
    vector<int> nums1{1, 2, 3, 0, 0, 0};
    vector<int> nums2{2, 5, 6};

    merge(nums1, 3, nums2, 3);

    for (auto n: nums1) {
        cout << n << ' ';
    }
    cout << endl;

    return 0;
}
