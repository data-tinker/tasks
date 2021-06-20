class Solution {
public:
    void dfs(const vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int>& currentPath, int vertex) {
        currentPath.push_back(vertex);

        if (vertex == graph.size() - 1) {
            paths.push_back(currentPath);
        } else {
            for (const auto& neighbourVetex: graph[vertex]) {
                dfs(graph, paths, currentPath, neighbourVetex);
            }
        }

        currentPath.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> currentPath;
        vector<vector<int>> paths;

        dfs(graph, paths, currentPath, 0);

        return paths;
    }
};
