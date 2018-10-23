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

void sortAnagrams(vector<string>& strs) {
    sort(strs.begin(), strs.end(), [](const string& lhs, const string& rhs){
        auto lhsSorted = lhs;
        auto rhsSorted = rhs;

        sort(lhsSorted.begin(), lhsSorted.end());
        sort(rhsSorted.begin(), rhsSorted.end());

        return lhsSorted < rhsSorted;
    });
}

int main() {
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};

    sortAnagrams(strs);

    for (const auto& s: strs) {
        cout << s << ' ';
    }
    cout << endl;

    auto anagrams = groupAnagrams(strs);

    for (const auto& a: anagrams) {
        for (const auto& s: a) {
            cout << s << ' ';
        }
        cout << endl;
    }

    return 0;
}
