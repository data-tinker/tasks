class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> charToOccurrence;
        int maxOccurrence = numeric_limits<int>::min();

        for (const auto c : S) {
            ++charToOccurrence[c];
            maxOccurrence = max(maxOccurrence, charToOccurrence[c]);
        }

        if (maxOccurrence > ceil(static_cast<double>(S.size()) / 2)) {
            return "";
        }

        priority_queue<pair<int, char>> occurrencesToChar;

        for (const auto& pair : charToOccurrence) {
            occurrencesToChar.emplace(pair.second, pair.first);
        }

        string result;
        while (occurrencesToChar.size() >= 2) {
            auto firstOccurrence = occurrencesToChar.top();
            occurrencesToChar.pop();
            auto secondOccurrence = occurrencesToChar.top();
            occurrencesToChar.pop();

            result += firstOccurrence.second;
            result += secondOccurrence.second;

            if (--firstOccurrence.first > 0) {
                occurrencesToChar.push(firstOccurrence);
            }
            if (--secondOccurrence.first > 0) {
                occurrencesToChar.push(secondOccurrence);
            }
        }

        if (!occurrencesToChar.empty()) {
            result += occurrencesToChar.top().second;
        }

        return result;
    }
};
