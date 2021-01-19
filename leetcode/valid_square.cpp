class Solution {
private:
    static double getDistance(const vector<int>& p1, const vector<int>& p2) {
        return sqrt(pow(abs(static_cast<double>(p1[0]) - p2[0]), 2) + pow(abs(static_cast<double>(p1[1]) - p2[1]), 2));
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points{p1, p2, p3, p4};

        sort(begin(points), end(points), [](const auto & lhs, const auto & rhs) -> bool {
            return lhs[0] == rhs[0] ? lhs[1] < rhs[1] : lhs[0] < rhs[0];
        });

        if (points[0] == points[3]) {
            return false;
        }

        if (
            getDistance(points[0], points[1]) == getDistance(points[2], points[3]) &&
            getDistance(points[0], points[2]) == getDistance(points[1], points[3]) &&
            getDistance(points[0], points[3]) == getDistance(points[1], points[2]) &&
            getDistance(points[0], points[1]) == getDistance(points[0], points[2])
           ) {
            return true;
        }

        return false;
    }
};
