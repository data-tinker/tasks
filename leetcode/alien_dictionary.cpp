class Solution {
private:
    enum State {
        NOT_VISITED,
        VISITING,
        VISITED
    };

    string topSort(const unordered_map<char, unordered_set<char>>& charToPrevious) {
        string order;
        unordered_set<char> unvisited;
        unordered_map<char, State> visited;

        for (const auto& pair : charToPrevious) {
            unvisited.insert(pair.first);
            visited[pair.first] = NOT_VISITED;
        }

        while (!unvisited.empty()) {
            auto unvisitedChar = *unvisited.begin();

            if (!dfs(charToPrevious, unvisited, visited, order, unvisitedChar)) {
                return "";
            }
        }

        reverse(begin(order), end(order));

        return order;
    }

    bool dfs(const unordered_map<char, unordered_set<char>>& charToPrevious, unordered_set<char>& unvisited, unordered_map<char, State>& visited, string& order, char unvisitedChar) {
        unvisited.erase(unvisitedChar);
        visited[unvisitedChar] = VISITING;

        bool result = true;

        for (const auto previousChar : charToPrevious.at(unvisitedChar)) {
            if (visited[previousChar] == VISITING) {
                return false;
            } else if (unvisited.find(previousChar) != unvisited.end()) {
                result &= dfs(charToPrevious, unvisited, visited, order, previousChar);
            }
        }

        visited[unvisitedChar] = VISITED;
        order += unvisitedChar;

        return result;
    }

public:
    string alienOrder(vector<string>& words) {
        if (words.size() == 1) {
            return words[0];
        }

        unordered_map<char, unordered_set<char>> charToPrevious;

        for (size_t i = 0; i < words.size() - 1; ++i) {
            for (const auto ch : words[i]) {
                charToPrevious[ch];
            }

            for (const auto ch : words[i + 1]) {
                charToPrevious[ch];
            }

            int minSize = min(words[i].length(), words[i + 1].length());

            bool isPrefix = true;
            for (size_t j = 0; j < minSize; ++j) {
                if (words[i][j] != words[i + 1][j]) {
                    charToPrevious[words[i][j]].insert(words[i + 1][j]);
                    isPrefix = false;
                    break;
                }
            }

            if (isPrefix && words[i + 1].length() < words[i].length()) {
                return "";
            }
        }

        return topSort(charToPrevious);
    }
};
