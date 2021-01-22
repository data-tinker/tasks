class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> charToCount;

        for (const auto c : s) {
            ++charToCount[c];
        }

        int numberOfOdds = 0;
        for (const auto& pair : charToCount) {
            if (pair.second % 2 != 0) {
                ++numberOfOdds;
            }
        }

        return numberOfOdds > 1 ? false : true;
    }
};
