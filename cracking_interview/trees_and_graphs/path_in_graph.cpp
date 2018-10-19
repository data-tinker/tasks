#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <queue>

bool pathExistsDfs(const std::vector<std::vector<int>>& graph, int start, int end) {
    std::stack<int> dfs;
    std::unordered_set<int> visited;
    dfs.push(start);

    while (!dfs.empty()) {
        auto vertex = dfs.top();
        dfs.pop();

        if (vertex == end) {
            return true;
        }

        for (const auto &neighbourVetex: graph[vertex]) {
            if (visited.find(neighbourVetex) == visited.end()) {
                dfs.push(neighbourVetex);
            }
        }

        visited.insert(vertex);
    }

    return false;
}

bool pathExistsBfs(const std::vector<std::vector<int>>& graph, int start, int end) {
    std::queue<int> bfs;
    std::unordered_set<int> visited;
    bfs.push(start);

    while (!bfs.empty()) {
        auto vertex = bfs.front();
        bfs.pop();

        if (vertex == end) {
            return true;
        }

        for (const auto &neighbourVetex: graph[vertex]) {
            if (visited.find(neighbourVetex) == visited.end()) {
                bfs.push(neighbourVetex);
            }
        }

        visited.insert(vertex);
    }

    return false;
}

int main() {
    int n, k, start, end;
    std::cin >> n >> k >> start >> end;
    --start;
    --end;

    std::vector<std::vector<int>> graph(n);

    for (size_t i = 0; i < k; ++i) {
        int v, e;
        std::cin >> v >> e;
        graph[v - 1].push_back(e - 1);
    }

    std::cout << pathExistsBfs(graph, start, end) << std::endl;

    return 0;
}
