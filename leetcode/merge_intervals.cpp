#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start = 0;
    int end = 0;

    Interval(int s, int e)
        : start(s)
        , end(e)
    {}

    Interval() = default;
};

class Solution {
public:
    static vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        sort(begin(intervals), end(intervals), [](const Interval& lhs, const Interval& rhs) {
            if (lhs.start == rhs.start) {
                return lhs.end < rhs.end;
            }

            return lhs.start < rhs.start;
        });

        vector<Interval> result{intervals.front()};

        for (const auto& interval: intervals) {
            auto& lastInterval = result.back();

            if (interval.start > lastInterval.end) {
                result.push_back(interval);
            } else if (interval.end > lastInterval.end) {
                lastInterval.end = interval.end;
            }
        }

        return result;
    }
};

int main() {
    int n, l, r;

    cin >> n;
    vector<Interval> intervals(n);

    for (auto& interval: intervals) {
        cin >> l >> r;
        interval.start = l;
        interval.end = r;
    }

    auto mergedIntervals = Solution::merge(intervals);

    for (const auto& interval: mergedIntervals) {
        cout << interval.start << ' ' << interval.end << endl;
    }

    return 0;
}
