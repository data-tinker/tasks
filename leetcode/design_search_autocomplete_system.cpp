class Trie {
public:
    Trie() : root(nullptr) {}

    void insert(const string& sentence, int times) {
        if (root == nullptr) {
            root = make_unique<TrieNode>();
        }

        TrieNode *currentNode = root.get();

        for (const auto &letter: sentence) {
            if (currentNode->nextChars[letter] == nullptr) {
                currentNode->nextChars[letter] = make_unique<TrieNode>();
            }

            currentNode = currentNode->nextChars[letter].get();
        }

        currentNode->times += times;
    }

    vector<pair<int, string>> lookup(string& sentence) const {
        if (root == nullptr) {
            return {};
        }

        TrieNode *currentNode = root.get();

        for (const auto& letter: sentence) {
            auto found = currentNode->nextChars.find(letter);

            if (found == currentNode->nextChars.end()) {
                return {};
            }

            currentNode = found->second.get();
        }

        vector<pair<int, string>> list;

        traverse(sentence, currentNode, list);

        return list;
    }

private:
    struct TrieNode {
        unordered_map<char, unique_ptr<TrieNode>> nextChars;
        int times = 0;
    };

    unique_ptr<TrieNode> root;

    void traverse(string& s, TrieNode* node, vector<pair<int, string>>& list) const {
        if (node->times > 0) {
            list.emplace_back(node->times, s);
        }

        for (const auto& pair : node->nextChars) {
            s += pair.first;
            traverse(s, pair.second.get(), list);
            s.pop_back();
        }
    }
};

class AutocompleteSystem {
private:
    Trie trie;
    string currentText;
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for (size_t i = 0; i < sentences.size(); ++i) {
            trie.insert(sentences[i], times[i]);
        }
    }

    vector<string> input(char c) {
        vector<string> result;

        if (c == '#') {
            trie.insert(currentText, 1);
            currentText = "";
        } else {
            currentText += c;
            vector<pair<int, string>> list = trie.lookup(currentText);

            sort(begin(list), end(list), [] (const auto& lhs, const auto& rhs) -> bool
            {
                return lhs.first > rhs.first ||
                     (lhs.first == rhs.first && lexicographical_compare(lhs.second.begin(), lhs.second.end(), rhs.second.begin(), rhs.second.end()));
            });

            for (size_t i = 0; i < min(3, static_cast<int>(list.size())); ++i) {
                result.push_back(list[i].second);
            }

        }

        return result;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
