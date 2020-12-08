class Solution {
private:
    vector<vector<char>> parseString(const string& S) {
        vector<vector<char>> parsedString;
        vector<char> currentOptions;
        bool inBrackets = false;

        for (const auto& c : S) {
            if (c == '{') {
                inBrackets = true;
            } else if (c == '}') {
                inBrackets = false;
                if (!currentOptions.empty()) {
                    parsedString.push_back(currentOptions);
                    currentOptions.clear();
                }
            } else if (isalpha(c)) {
                if (inBrackets) {
                    currentOptions.push_back(c);
                } else {
                    parsedString.push_back({c});
                }
            }
        }

        if (!currentOptions.empty()) {
            parsedString.push_back(currentOptions);
        }

        return parsedString;
    }

    void dfs(vector<string>& expandedStrings, const vector<vector<char>>& parsedString, int idx, string& currentString) {
        if (idx == parsedString.size()) {
            expandedStrings.push_back(currentString);
            return;
        }

        for (const auto& c : parsedString[idx]) {
            currentString += c;
            dfs(expandedStrings, parsedString, idx + 1, currentString);
            currentString.pop_back();
        }
    }
public:
    vector<string> expand(string S) {
        auto parsedString = parseString(S);

        vector<string> expandedStrings;
        string currentString;

        dfs(expandedStrings, parsedString, 0, currentString);

        sort(begin(expandedStrings), end(expandedStrings));

        return expandedStrings;
    }
};
