class Solution {
private:
    bool isIsomorphicMap(string s, string t) {
        int sCharCount = 1;
        int tCharCount = 1;

        char sChar = s[0];
        char tChar = t[0];

        unordered_map<char, char> sCharToTChar;
        unordered_map<char, char> tCharToSChar;

        for (size_t i = 1; i < s.length(); ++i) {
            if (sCharCount == tCharCount) {
                auto foundS = tCharToSChar.find(tChar);
                auto foundT = sCharToTChar.find(sChar);

                if (foundS == tCharToSChar.end()) {
                    tCharToSChar[tChar] = sChar;
                }

                if (foundT == sCharToTChar.end()) {
                    sCharToTChar[sChar] = tChar;
                }

                if (tCharToSChar[tChar] != sChar || sCharToTChar[sChar] != tChar) {
                    return false;
                }
            } else {
                return false;
            }

            if (s[i] == sChar) {
                ++sCharCount;
            } else {
                sChar = s[i];
                sCharCount = 1;
            }

            if (t[i] == tChar) {
                ++tCharCount;
            } else {
                tChar = t[i];
                tCharCount = 1;
            }
        }

        if (sCharCount == tCharCount) {
            auto foundS = tCharToSChar.find(tChar);
            auto foundT = sCharToTChar.find(sChar);

            if (foundS == tCharToSChar.end()) {
                tCharToSChar[tChar] = sChar;
            }

            if (foundT == sCharToTChar.end()) {
                sCharToTChar[sChar] = tChar;
            }

            if (tCharToSChar[tChar] != sChar || sCharToTChar[sChar] != tChar) {
                return false;
            }
        } else {
            return false;
        }

        return true;
    }

    bool isIsomorphicFast(const string& s, const string& t) {
        vector<int> sCharToIdx(256);
        vector<int> tCharToIdx(256);

        for (size_t i = 0; i < s.length(); ++i) {
            if (sCharToIdx[s[i]] != tCharToIdx[t[i]]) {
                return false;
            }

            sCharToIdx[s[i]] = i + 1;
            tCharToIdx[t[i]] = i + 1;
        }

        return true;
    }
public:
    bool isIsomorphic(string s, string t) {
        return isIsomorphicFast(s, t);
    }
};
