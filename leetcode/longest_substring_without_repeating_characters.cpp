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

//size_t lengthOfLongestSubstring(const string& s) {
//    if (s.empty()) {
//        return 0;
//    }
//
//    size_t l = 0;
//    size_t r = 0;
//
//    unordered_set<char> currentWindow;
//
//    size_t result = numeric_limits<size_t>::min();
//
//    for (auto c: s) {
//        if (currentWindow.find(c) != currentWindow.end()) {
//            while (s[l] != c) {
//                currentWindow.erase(s[l]);
//                ++l;
//            }
//
//            currentWindow.erase(c);
//            ++l;
//        }
//
//        currentWindow.insert(c);
//        result = max({result, r - l + 1});
//        ++r;
//    }
//
//    return result;
//}

size_t lengthOfLongestSubstring(const string& s) {
    if (s.empty()) {
        return 0;
    }

    unordered_map<char, size_t> currentWindow;

    size_t result = numeric_limits<size_t>::min();

    for (size_t l = 0, r = 0; r < s.size(); ++r) {
        l = max(currentWindow[s[r]], l);
        result = max(r - l + 1, result);
        currentWindow[s[r]] = r + 1;
    }

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    string s;
    cin >> s;

    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}
