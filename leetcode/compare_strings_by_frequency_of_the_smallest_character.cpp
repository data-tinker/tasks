class Solution {
private:
    int f(const string& s) {
        array<int, 26> charCount;
        charCount.fill(0);

        for (const auto c : s) {
            ++charCount[c - 'a'];
        }

        for (const auto i : charCount) {
            if (i > 0) {
                return i;
            }
        }

        return 0;
    }
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> wordsF;

        for (const auto& s : words) {
            wordsF.push_back(f(s));
        }

        sort(begin(wordsF), end(wordsF));

        vector<int> result;
        for (const auto& s : queries) {
            auto sF = f(s);

            result.push_back(words.size() - (upper_bound(begin(wordsF), end(wordsF), sF) - begin(wordsF)));
        }

        return result;
    }
};
