#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    static int countBits(int n) {
        int count = 0;
        while (n != 0) {
            count++;
            n >>= 1;
        }

        return count;
    }

    static int computeDistance(const vector<int>& p1, const vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<vector<int>> dp(workers.size() + 1, vector<int>(1 << bikes.size(), 1000000));
        dp[0][0] = 0;

        for (size_t i = 0; i < workers.size(); ++i) {
            for (int state = 0; state < (1 << bikes.size()); ++state) {
                for (size_t j = 0; j < bikes.size(); ++j) {
                    int newState = state | (1 << j);
                    if ((state & (1 << j)) == 0) {
                        dp[i + 1][newState] = min(
                            dp[i + 1][newState],
                            dp[i][state] + computeDistance(workers[i], bikes[j])
                        );
                    }
                }
            }
        }

        return *min_element(dp[workers.size()].begin(), dp[workers.size()].end());
    }
};

int main() {
    vector<vector<int>> workers{{0,0},{2,1}};
    vector<vector<int>> bikes{{1,2},{3,3}};

    cout << Solution().assignBikes(workers, bikes) << endl;

    return 0;
}
