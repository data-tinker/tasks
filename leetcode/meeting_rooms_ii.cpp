class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, vector<bool>> points;
        for (const auto& interval : intervals) {
            points[interval[0]].push_back(true);
            points[interval[1]].push_back(false);
        }

        int numOfRooms = 0;
        int maxNumberOfRooms = numeric_limits<int>::min();
        for (const auto& point : points) {
            for (const auto isStart : point.second) {
                if (isStart) {
                    ++numOfRooms;
                } else {
                    --numOfRooms;
                }
            }

            maxNumberOfRooms = max(maxNumberOfRooms, numOfRooms);
        }

        return maxNumberOfRooms;
    }
};
