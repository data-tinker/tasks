#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <cassert>
#include <fstream>
#include <array>

using namespace std;

#define endl '\n'

void nextPermutation(vector<int>& nums) {
    int l = nums.size() - 1;
    int r = nums.size() - 1;

    while (l > 0 && nums[l - 1] >= nums[l]) {
        --l;
    }

    while (nums[r] < nums[l - 1]) {
        --r;
    }

    swap(nums[l - 1], nums[r]);

    r = nums.size() - 1;

    while (l < r) {
        swap(nums[l++], nums[r--]);
    }
}

string getPermutation(int n, int k) {
    vector<int> nums;

    for (size_t i = 1; i <= n; ++i) {
        nums.push_back(i);
    }

    for (size_t i = 0; i < k - 1; ++i) {
        nextPermutation(nums);
    }

    string result = "";

    for (size_t i = 0; i < n; ++i) {
        result += to_string(nums[i]);
    }

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    cout << getPermutation(3, 1) << endl;

    return 0;
}
