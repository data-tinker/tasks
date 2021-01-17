class Trie {
private:
    struct TrieNode {
        array<unique_ptr<TrieNode>, 26> children;
        bool end = false;
    };

    unique_ptr<TrieNode> head;

    inline size_t getIdx(char c) {
        return c - 'a';
    }

    TrieNode* iterateWord(const string& word) {
        auto current = head.get();

        for (const auto c : word) {
            size_t idx = getIdx(c);

            if (!current->children[idx]) {
                return nullptr;
            }

            current = current->children[idx].get();
        }

        return current;
    }
public:
    /** Initialize your data structure here. */
    Trie() {
        head = make_unique<TrieNode>();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto current = head.get();

        for (const auto c : word) {
            size_t idx = getIdx(c);

            if (!current->children[idx]) {
                current->children[idx] = make_unique<TrieNode>();
            }

            current = current->children[idx].get();
        }

        current->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto current = iterateWord(word);

        if (!current) {
            return false;
        }

        return current->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto current = iterateWord(prefix);

        if (!current) {
            return false;
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
