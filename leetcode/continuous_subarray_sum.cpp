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

bool checkSubarraySum(const vector<int>& nums, int k) {
    vector<int> prefixSums{0};

    int currentSum = 0;

    for (auto n : nums) {
        currentSum += n;
        prefixSums.push_back(currentSum);
    }

//    for (auto p: prefixSums) {
//        cout << p << ' ';
//    }
//    cout << endl;

    for (size_t i = 0; i <= nums.size(); ++i) {
        for (size_t j = i + 2; j <= nums.size(); ++j) {
            currentSum = prefixSums[j] - prefixSums[i];

            if (k != 0 && currentSum >= k && currentSum % k == 0) {
                return true;
            } else if (currentSum == 0) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    cout << checkSubarraySum({0, 0}, 0);

    return 0;
}
