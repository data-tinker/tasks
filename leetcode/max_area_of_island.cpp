class Solution {
private:
    array<pair<int, int>, 4> nb = {{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }

        int n = grid.size();
        int m = grid[0].size();

        int maxArea = 0;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    int area = 0;

                    queue<pair<int, int>> cellsQueue;
                    cellsQueue.emplace(i, j);
                    grid[i][j] = 0;

                    while (!cellsQueue.empty()) {
                        ++area;
                        auto cell = cellsQueue.front();
                        cellsQueue.pop();

                        for (const auto& nbShift : nb) {
                            int nbi = cell.first + nbShift.first;
                            int nbj = cell.second + nbShift.second;

                            if (nbi < n && nbi >= 0 && nbj < m && nbj >= 0) {
                                if (grid[nbi][nbj] == 1) {
                                    cellsQueue.emplace(nbi, nbj);
                                    grid[nbi][nbj] = 0;
                                }
                            }
                        }
                    }

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
