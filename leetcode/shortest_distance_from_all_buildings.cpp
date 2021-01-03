class Solution {
private:
    static constexpr const pair<int, int> Neighbours[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    void bfs(const vector<vector<int>>& grid, vector<vector<pair<int, int>>>& distanceAndReachable, const pair<int, int>& startPoint, int numberOfBuildings) {
        queue<pair<int, int>> pointsQueue;

        pointsQueue.push(startPoint);
        int distance = 1;

        while (!pointsQueue.empty()) {
            int queueSize = pointsQueue.size();

            for (size_t i = 0; i < queueSize; ++i) {
                auto point = pointsQueue.front();
                pointsQueue.pop();

                for (const auto& nb : Neighbours) {
                    auto nbPoint = make_pair(point.first + nb.first, point.second + nb.second);

                    if (nbPoint.first >= 0 && nbPoint.first < grid.size() && nbPoint.second >= 0 && nbPoint.second < grid[0].size() &&
                        grid[nbPoint.first][nbPoint.second] == 0 && distanceAndReachable[nbPoint.first][nbPoint.second].second == numberOfBuildings - 1) {
                        distanceAndReachable[nbPoint.first][nbPoint.second].first += distance;
                        distanceAndReachable[nbPoint.first][nbPoint.second].second = numberOfBuildings;
                        pointsQueue.push(nbPoint);
                    }
                }
            }

            ++distance;
        }
    }
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int numberOfBuildings = 0;
        vector<vector<pair<int, int>>> distanceAndReachable(n, vector<pair<int, int>>(m));

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    ++numberOfBuildings;

                    bfs(grid, distanceAndReachable, {i, j}, numberOfBuildings);
                }
            }
        }

        int result = numeric_limits<int>::max();

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                if (distanceAndReachable[i][j].second == numberOfBuildings) {
                    result = min(result, distanceAndReachable[i][j].first);
                }
            }
        }

        if (result == numeric_limits<int>::max()) {
            return -1;
        }

        return result;
    }
};
