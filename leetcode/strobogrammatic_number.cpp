class Solution {
private:
    static const unordered_map<char, char> NumberToRotated;
    static const unordered_set<char> SymmetricNumbers;
public:
    bool isStrobogrammatic(string num) {
        size_t l = 0;
        size_t r = num.length() - 1;

        while (l < r) {
            auto it = NumberToRotated.find(num[l]);
            if (it == NumberToRotated.end()) {
                return false;
            } else if (it->second != num[r]) {
                return false;
            }

            ++l;
            --r;
        }

        if (num.length() % 2 != 0) {
            if (SymmetricNumbers.find(num[num.length() / 2]) == SymmetricNumbers.end()) {
                return false;
            }
        }

        return true;
    }
};

const unordered_map<char, char> Solution::NumberToRotated = {
    {'0', '0'},
    {'1', '1'},
    {'8', '8'},
    {'6', '9'},
    {'9', '6'}
};


const unordered_set<char> Solution::SymmetricNumbers = {
    {'0', '1', '8'},
};
