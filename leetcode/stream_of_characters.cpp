class StreamChecker {
private:
    struct Node {
        array<unique_ptr<Node>, 26> Children;
        bool isLeaf;

        Node()
            : isLeaf(false)
        {}

         Node* addChild(char c) {
             c -= 'a';
             if (Children[c] == nullptr) {
                Children[c] = make_unique<Node>();
             }

             return Children[c].get();
         }
    };

    unique_ptr<Node> Root;
    deque<char> QueriesChars;
    static const int MAX_WORD_LENGTH = 2000;
public:
    StreamChecker(vector<string>& words) {
        Root = make_unique<Node>();

        for (const auto& word : words) {
            auto* currentNode = Root.get();

            for (int i = word.size() - 1; i >= 0; --i) {
                currentNode = currentNode->addChild(word[i]);
            }

            currentNode->isLeaf = true;
        }
    }

    bool query(char letter) {
        if (QueriesChars.size() < MAX_WORD_LENGTH) {
            QueriesChars.push_front(letter);
        } else {
            QueriesChars.push_front(letter);
            QueriesChars.pop_back();
        }

        auto* currentNode = Root.get();

        for (auto c : QueriesChars) {
            c -= 'a';
            if (currentNode->isLeaf) {
                return true;
            } else if (currentNode->Children[c] == nullptr) {
                return false;
            }

            currentNode = currentNode->Children[c].get();
        }

        return currentNode->isLeaf;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
