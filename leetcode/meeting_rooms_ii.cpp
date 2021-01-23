struct Point {
    int coordinate;
    bool end;
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<Point> points;
        for (const auto& interval : intervals) {
            points.push_back({interval[0], false});
            points.push_back({interval[1] - 1, true});
        }

        sort(begin(points), end(points), [](const auto& lhs, const auto& rhs) {
           return lhs.coordinate == rhs.coordinate ? lhs.end < rhs.end : lhs.coordinate < rhs.coordinate;
        });

        int numOfRooms = 0;
        int maxNumberOfRooms = numeric_limits<int>::min();
        for (const auto& point : points) {
            if (point.end) {
                --numOfRooms;
            } else {
                ++numOfRooms;
            }

            maxNumberOfRooms = max(maxNumberOfRooms, numOfRooms);
        }

        return maxNumberOfRooms;
    }
};
