class Solution {
public:
    bool queryString(string S, int N) {
        string NtoBin;

        int tmp = N;
        while (tmp) {
            if (tmp % 2 == 1) {
                NtoBin += '1';
            } else {
                NtoBin += '0';
            }

            tmp >>= 1;
        }

        reverse(NtoBin.begin(), NtoBin.end());
        unordered_set<string> nums;

        for (size_t i = 0; i < S.size(); ++i) {
            if (S[i] == '0') {
                continue;
            }

            for (size_t len = 1; len <= 30 && len + i - 1 < S.size(); ++len) {
                string subS = S.substr(i, len);

                if (subS.size() > NtoBin.size() ||  (subS.size() == NtoBin.size() && subS > NtoBin)) {
                    break;
                }

                nums.insert(subS);
            }
        }

        return nums.size() == N;
    }
};
