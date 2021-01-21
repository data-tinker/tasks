class UnionFind {
private:
    int count = 0;
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(vector<vector<char>>& grid)
        : parent(grid.size() * grid[0].size(), -1)
        , rank(grid.size() * grid[0].size(), 0)
    {
        size_t n = grid.size();
        size_t m = grid[0].size();

        for (size_t i = 0; i < n; ++i) {
          for (size_t j = 0; j < m; ++j) {
              if (grid[i][j] == '1') {
                  parent[i * m + j] = i * m + j;
                  ++count;
              }
          }
        }
    }

    int findSet(int i) {
        if (parent[i] != i) {
            parent[i] = findSet(parent[i]);
        }

        return parent[i];
    }

    void unionSets(int x, int y) {
        int parentX = findSet(x);
        int parentY = findSet(y);

        if (parentX != parentY) {
            if (rank[parentX] > rank[parentY]) {
                parent[parentY] = parentX;
            } else if (rank[parentX] < rank[parentY]) {
                parent[parentX] = parentY;
            } else {
                parent[parentY] = parentX;
                rank[parentX] += 1;
            }
            --count;
        }
    }

    int getCount() {
        return count;
    }
};

class Solution {
private:
    static constexpr pair<int, int> neighbours[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int numIslandsDSU(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int num = 0;
        UnionFind unionFind(grid);
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    grid[i][j] == '0';

                    for (const auto& nb : neighbours) {
                        int nbRow = i + nb.first;
                        int nbCol = j + nb.second;

                        if (nbRow < n && nbRow >= 0 && nbCol < m && nbCol >= 0 &&
                           grid[nbRow][nbCol] == '1') {
                            unionFind.unionSets(i * m + j, nbRow * m + nbCol);
                        }
                    }
                }
            }
        }

        return unionFind.getCount();
    }

    void dfs(vector<vector<char>>& grid, int row, int col) {
        for (const auto& nb : neighbours) {
            int nbRow = row + nb.first;
            int nbCol = col + nb.second;

            if (nbRow < grid.size() && nbRow >= 0 && nbCol < grid[0].size() && nbCol >= 0 &&
                grid[nbRow][nbCol] == '1') {
                grid[nbRow][nbCol] = '0';
                dfs(grid, nbRow, nbCol);
            }
        }
    }

    int numIslandsDFS(vector<vector<char>>& grid) {
        int num = 0;
        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++num;
                    grid[i][j] = '0';
                    dfs(grid, i, j);
                }
            }
        }

        return num;
    }

    void bfs(vector<vector<char>>& grid, const pair<int, int>& startNode) {
        queue<pair<int, int>> nodesQueue;

        grid[startNode.first][startNode.second] = '0';
        nodesQueue.push(startNode);

        while (!nodesQueue.empty()) {
            auto node = nodesQueue.front();
            nodesQueue.pop();


            for (const auto& nbShift : neighbours) {
                auto nb = make_pair(node.first + nbShift.first, node.second + nbShift.second);

                if (nb.first < grid.size() && nb.first >= 0 && nb.second < grid[0].size() && nb.second >= 0 &&
                   grid[nb.first][nb.second] == '1') {
                    grid[nb.first][nb.second] = '0';
                    nodesQueue.push(nb);
                }
            }
        }
    }

    int numIslandsBFS(vector<vector<char>>& grid) {
        int num = 0;
        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++num;
                    bfs(grid, make_pair(i, j));
                }
            }
        }

        return num;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        return numIslandsDSU(grid);
    }
};

