struct Point {
    int height;
    bool start;
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<int, vector<Point>> coordinatesToPoints;

        for (const auto& building : buildings) {
            coordinatesToPoints[building[0]].push_back({building[2], true});
            coordinatesToPoints[building[1]].push_back({building[2], false});
        }

        multiset<int> heights;
        vector<vector<int>> result;

        for (const auto& coordinateToPoints : coordinatesToPoints) {
            int lastHeight = heights.empty() ? 0 : *heights.rbegin();

            for (const auto& point : coordinateToPoints.second) {
                if (point.start) {
                    heights.insert(point.height);
                } else {
                    heights.erase(heights.find(point.height));
                }
            }

            int currentHeight = heights.empty() ? 0 : *heights.rbegin();

            if (lastHeight != currentHeight) {
                result.push_back({coordinateToPoints.first , currentHeight});
            }
        }

        return result;
    }
};
