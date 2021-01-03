class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) {
            return false;
        }

        unordered_map<string, unordered_set<string>> similar;
        for (const auto& pair : similarPairs) {
            similar[pair[0]].insert(pair[1]);
            similar[pair[1]].insert(pair[0]);
        }

        for (size_t i = 0; i < sentence1.size(); ++i) {
            if (sentence1[i] == sentence2[i]) {
                continue;
            }

            auto findWord = similar.find(sentence1[i]);
            if (findWord != similar.end() && findWord->second.find(sentence2[i]) != findWord->second.end()) {
                continue;
            }

            return false;
        }

        return true;
    }
};
