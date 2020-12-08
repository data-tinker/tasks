class Solution {
public:
    string removeDuplicates(string S) {
        string result;
        char topChar;

        for (const auto& c : S) {
            if (!result.empty()) {
                topChar = result.back();

                if (topChar == c) {
                    result.pop_back();
                } else {
                    result += c;
                }
            } else {
                result += c;
            }
        }

        return result;
    }
};
