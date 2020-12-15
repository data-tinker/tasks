class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }

        sort(begin(points), end(points), [](const auto& lhs, const auto& rhs) {
            return lhs[1] < rhs[1];
        });

        int arrowsCount = 1;
        int currentArrow = points[0][1];

        for (size_t i = 1; i < points.size(); ++i) {
            if (points[i][0] > currentArrow) {
                currentArrow = points[i][1];
                ++arrowsCount;
            }
        }

        return arrowsCount;
    }

    int findMinArrowShotsSortByFirst(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }

        sort(begin(points), end(points));

        int arrowsCount = 1;
        int currentArrow = points[0][1];

        for (size_t i = 1; i < points.size(); ++i) {
            if (points[i][0] > currentArrow) {
                currentArrow = points[i][1];
                ++arrowsCount;
            } else {
                currentArrow = min(points[i][1], currentArrow);
            }
        }

        return arrowsCount;
    }
};
