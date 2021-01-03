class DSU {
public:
    DSU(const size_t size)
        : parent(size)
        , rank(size)
    {
        for (size_t i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find_set(int x) {
        if (x != parent[x]) {
            parent[x] = find_set(parent[x]);
        }
        return parent[x];
    }

    bool union_sets(int x, int y) {
        int xp = find_set(x);
        int yp = find_set(y);

        if (xp == yp) {
            return false;
        } else if (rank[xp] < rank[yp]) {
            parent[xp] = yp;
        } else if (rank[xp] > rank[yp]) {
            parent[yp] = xp;
        } else {
            parent[xp] = yp;
            ++rank[yp];
        }

        return true;
    }

    void print() {
        for (size_t i = 0; i < parent.size(); ++i) {
            cout << i << ' ' << parent[i] << endl;
        }
    }
private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
private:
    bool findWord(const unordered_map<string, unordered_set<string>>& similar, const string& startWord,  const string& endWord) {
        unordered_set<string> visited;
        stack<string> stringStack;

        visited.insert(startWord);
        stringStack.push(startWord);

        while (!stringStack.empty()) {
            auto word = stringStack.top();
            stringStack.pop();

            auto found = similar.find(word);

            if (found != similar.end()) {
                for (const auto& nbWord :  found->second) {
                    if (nbWord == endWord) {
                        return true;
                    }

                    if (visited.find(nbWord) == visited.end()) {
                        visited.insert(nbWord);
                        stringStack.push(nbWord);
                    }
                }
            }
        }

        return false;
    }

    bool areSentencesSimilarTwoDFS(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) {
            return false;
        }

        unordered_map<string, unordered_set<string>> similar;
        for (const auto& pair : pairs) {
            similar[pair[0]].insert(pair[1]);
            similar[pair[1]].insert(pair[0]);
        }

        for (size_t i = 0; i < words1.size(); ++i) {
            if (words1[i] == words2[i]) {
                continue;
            }

            bool found = findWord(similar, words1[i], words2[i]);
            if (found) {
                continue;
            }

            return false;
        }

        return true;
    }

    bool areSentencesSimilarTwoDSU(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) {
            return false;
        }

        unordered_map<string, int> index;
        int count = 0;
        DSU dsu(2 * pairs.size());

        for (const auto& pair : pairs) {
            for (const auto& word : pair) {
                if (index.find(word) == index.end()) {
                    index[word] = count++;
                }
            }

            dsu.union_sets(index[pair[0]], index[pair[1]]);
        }

        for (size_t i = 0; i < words1.size(); ++i) {
            if (words1[i] == words2[i]) {
                continue;
            }

            auto found1 = index.find(words1[i]);
            auto found2 = index.find(words2[i]);

            if (found1 == index.end() || found2 == index.end() ||
                    dsu.find_set(found1->second) != dsu.find_set(found2->second)) {
                return false;
            }
        }

        return true;
    }
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        return areSentencesSimilarTwoDSU(words1, words2, pairs);
    }
};
