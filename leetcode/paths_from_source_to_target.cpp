#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <queue>

using namespace std;

void dfs(const vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int>& currentPath, vector<bool>& visited, int vertex) {
    if (visited[vertex]) {
        return;
    }

    visited[vertex] = true;

    currentPath.push_back(vertex);

    if (vertex == graph.size() - 1) {
        paths.push_back(currentPath);
    }

    for (const auto& neighbourVetex: graph[vertex]) {
        dfs(graph, paths, currentPath, visited, neighbourVetex);
    }

    visited[vertex] = false;

    currentPath.pop_back();
}

vector<vector<int>> findPaths(const std::vector<std::vector<int>>& graph) {
    vector<int> currentPath;
    vector<vector<int>> paths;
    vector<bool> visited(graph.size(), false);

    dfs(graph, paths, currentPath, visited, 0);

    return paths;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> graph(n);

    for (size_t i = 0; i < k; ++i) {
        int v, e;
        std::cin >> v >> e;
        graph[v].push_back(e);
    }

    for (const auto& p: findPaths(graph)) {
        for (auto v: p) {
            cout << v << ' ';
        }
        cout << endl;
    }

    return 0;
}
