#include <iostream>
#include <unordered_map>
#include <limits>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string minWindow(string str, string t) {
        unordered_map<char, int> slidingWindow;

        for (const auto c : t) {
            ++slidingWindow[c];
        }

        size_t l = 0;
        size_t r = 0;
        string shortestSubstring = "";

        while (r < str.length()) {
            bool isEnough = true;

            for (const auto& pair : slidingWindow) {
                if (pair.second > 0) {
                    isEnough = false;
                    break;
                }
            }

            if (isEnough) {
                if (shortestSubstring.empty() || (r - l < shortestSubstring.length())) {
                    shortestSubstring = str.substr(l, r - l);
                }
                ++slidingWindow[str[l]];
                ++l;
            } else {
                --slidingWindow[str[r]];
                ++r;
            }
        }

        while (l < str.length()) {
            bool isEnough = true;

            for (const auto& pair : slidingWindow) {
                if (pair.second > 0) {
                    isEnough = false;
                    break;
                }
            }

            if (isEnough) {
                if (shortestSubstring.empty() || (r - l < shortestSubstring.length())) {
                    shortestSubstring = str.substr(l, r - l);
                }
            }

            ++slidingWindow[str[l]];
            ++l;
        }

        return shortestSubstring;
    }
};

int main() {
    cout << Solution().minWindow("ADOBECODEBANC", "ABC") << endl;

    return 0;
}
