namespace std {
    template<>
    struct hash<std::pair<int, int> > {
        size_t operator()(const std::pair<int, int> &p) const {
            return std::hash<int>()(p.first) ^ std::hash<int>()(p.second);
        }
    };
}

class Solution {
private:
    unordered_map<pair<int, int>, int> Memo;
public:
    int minDistance(string word1, string word2) {
        return recurse(word1, 0, word2, 0);
    }

    int recurse(const string& word1, size_t idx1, const string& word2, size_t idx2) {
    	if (idx1 == word1.size() || idx2 == word2.size()) {
        	return word2.size() - idx2 + word1.size() - idx1;
		}

        auto memoKey = make_pair(idx1, idx2);
        if (Memo.find(memoKey) != Memo.end()) {
        	return Memo[memoKey];
		}

        int result = numeric_limits<int>::max();

    	if (word1[idx1] == word2[idx2]) {
        	result = recurse(word1, idx1 + 1, word2, idx2 + 1);
      	} else {
        	result = min(result, recurse(word1, idx1 + 1, word2, idx2) + 1);
            result = min(result, recurse(word1, idx1, word2, idx2 + 1) + 1);
        }

        Memo[memoKey] = result;

        return Memo[memoKey];
  	}
};
