#include <iostream>
#include <unordered_map>
#include <limits>
#include <unordered_set>

using namespace std;

bool isSubSet(unordered_map<char, int> ss, unordered_map<char, int> s) {
    for (const auto& [c, i] : s) {
        if (ss.find(c) == s.end()) {
            return false;
        }

        if (ss[c] < s[c]) {
            return false;
        }
    }

    return true;
}

string minWindow(string s, string t) {
    if (t.size() == 0) {
        return "";
    }

    unordered_map<char, int> w;
    unordered_map<char, int> tw;
    int ts = 0;

    for (const auto& c : t) {
        ++tw[c];
    }

    size_t tSize = tw.size();

    size_t r = 0, rr, resultSize = numeric_limits<size_t>::max();
    size_t l = 0, lr;

    while (r < s.size()) {
        if (ts == tSize) {
            if (r - l < resultSize) {
                resultSize = r - l;
                lr = l;
                rr = r;
            }
            --w[s[l]];

            if (tw.find(s[l]) != tw.end() && w[s[l]] == tw[s[l]] - 1) {
                --ts;
            }

            ++l;
        } else {
            ++w[s[r]];

            if (tw.find(s[r]) != tw.end() && w[s[r]] == tw[s[r]]) {
                ++ts;
            }

            ++r;
        }
    }

    while (l < s.size()) {
        if (ts == tSize) {
            if (r - l < resultSize) {
                resultSize = r - l;
                lr = l;
                rr = r;
            }
        }

        --w[s[l]];

        if (tw.find(s[l]) != tw.end() && w[s[l]] == tw[s[l]] - 1) {
            --ts;
        }

        ++l;
    }

    string result = "";

    if (resultSize == numeric_limits<size_t>::max()) {
        return result;
    }

    for (size_t i = lr; i < rr; ++i) {
        result += s[i];
    }

    return result;
}

int main() {
    cout << minWindow("ADOBECODEBANC", "ABC") << endl;

    return 0;
}
