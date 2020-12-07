class Solution {
private:
    int upperBound(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int l = 0;
        int r = intervals.size();
        int m;

        while (l < r) {
            m = (l + r) / 2;

            if (intervals[m][0] <= newInterval[0]) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        return l;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int insertIdx = upperBound(intervals, newInterval);
        intervals.insert(intervals.begin() + insertIdx, newInterval);

        for (size_t i = 0; i < intervals.size(); ++i) {
            if (!result.empty() && intervals[i][0] <= result.back()[1]) {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};
