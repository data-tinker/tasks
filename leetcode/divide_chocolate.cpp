class Solution {
private:
    bool canSplit(vector<int>& sweetness, int k, int minSweetness) {
        int sumSweetness = 0;
        int count = 0;

        for (const auto s : sweetness) {
            sumSweetness += s;

            if (sumSweetness >= minSweetness) {
                sumSweetness = 0;
                ++count;
            }
        }

        return count > k;
    }
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int l = numeric_limits<int>::max();
        int r = 0;

        for (const auto s : sweetness) {
            l = min(l, s);
            r += s;
        }

        while (l < r) {
            int m = (l + r + 1) / 2;

            if (canSplit(sweetness, k, m)) {
                l = m;
            } else {
                r = m - 1;
            }
        }

        return r;
    }
};
