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

int longestConsecutive(const vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    unordered_set<int> numsSet;
    int result = numeric_limits<int>::min();

    for (auto num : nums) {
        numsSet.insert(num);
    }

    for (auto num : numsSet) {
        if (numsSet.find(num - 1) == numsSet.end()) {
            int currentNum = num;
            int currentResult = 1;

            while (numsSet.find(++currentNum) != numsSet.end()) {
                ++currentResult;
            }

            result = max(result, currentResult);
        }
    }

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    cout << longestConsecutive({100, 4, 200, 1, 3, 2}) << endl;

    return 0;
}
