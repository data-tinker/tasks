#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Interval {
    int start;
    int end;

    Interval()
        : start(0)
        , end(0)
    {}

    Interval(int s, int e)
        : start(s)
        , end(e)
    {}
};

vector<Interval> merge(vector<Interval>& intervals) {
    if (intervals.empty()) {
        return vector<Interval>();
    }

    sort(intervals.begin(), intervals.end(), [](const auto & lhs, const auto & rhs){
        return lhs.start < rhs.start;
    });

    vector<Interval> result;
    int currentEnd = numeric_limits<int>::min();

    for (const auto & interval: intervals) {
        if (interval.start > currentEnd) {
            result.push_back(interval);
            currentEnd = interval.end;
        } else {
            currentEnd = max(interval.end, currentEnd);
            result.back().end = currentEnd;
        }
    }

    return result;
}

int main() {
    vector<Interval> intervals{{1,3}, {2,6}, {8,10}, {15,18}};

    auto mergedIntervals = merge(intervals);

    for (const auto & interval : mergedIntervals) {
        cout << interval.start << ' ' << interval.end << endl;
    }

    return 0;
}
