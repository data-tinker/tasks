#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string getShortestUniqueSubstring( const vector<char>& arr, const string &str )
{
    unordered_map<char, int> slidingWindow;

    for (const auto c : arr) {
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

int main() {
    return 0;
}
