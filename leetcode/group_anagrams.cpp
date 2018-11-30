#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(const vector<string>& strs) {
    unordered_map<string, vector<string>> strToAnagrams;

    for (const auto& s: strs) {
        string sSorted = s;
        sort(sSorted.begin(), sSorted.end());
        strToAnagrams[sSorted].push_back(s);
    }

    vector<vector<string>> anagrams;

    for (const auto &strToAnagram: strToAnagrams) {
        anagrams.push_back(strToAnagram.second);
    }

    return anagrams;
}

int main() {
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};

    auto anagrams = groupAnagrams(strs);

    for (const auto& a: anagrams) {
        for (const auto& s: a) {
            cout << s << ' ';
        }
        cout << endl;
    }

    return 0;
}
