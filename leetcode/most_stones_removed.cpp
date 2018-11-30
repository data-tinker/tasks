#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;


void dfs(vector<vector<int>>& graph, unordered_set<int>& nodes, int v, int n, int& connectedSize) {
    stack<int> s;
    s.push(v);

    while (!s.empty()) {
        int v = s.top();
        s.pop();

        for (int i: graph[v]) {
            if (nodes.find(i) != nodes.end()) {
                s.push(i);
                nodes.erase(i);
                ++connectedSize;
            }
        }
    }
}

int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();

    unordered_map<int, int> rowToId;
    unordered_map<int, int> colToId;
    int result = 0;

    vector<vector<int>> graph(n);

    for (size_t i = 0; i < n; ++i) {
        int row = stones[i][0];
        int col = stones[i][1];

        if (rowToId.find(row) != rowToId.end()) {
            int rowConnectId = rowToId[row];

            graph[i].push_back(rowConnectId);
            graph[rowConnectId].push_back(i);
        }

        if (colToId.find(col) != colToId.end()) {
            int colConectId = colToId[col];

            graph[i].push_back(colConectId);
            graph[colConectId].push_back(i);
        }

        rowToId[row] = i;
        colToId[col] = i;
    }

    unordered_set<int> nodes;

    for (size_t i = 0; i < n; ++i) {
        nodes.insert(i);
    }

//    for (size_t i = 0; i < n; ++i) {
//        cout << i << ": ";
//        for (auto j: graph[i]) {
//            cout << j << ' ';
//        }
//        cout << endl;
//    }

    while (!nodes.empty()) {
        int connectedSize = 0;
        int v = *nodes.begin();

        nodes.erase(v);

        dfs(graph, nodes, v, n, connectedSize);

        result += connectedSize;
    }

    return result;
}

int main() {
    vector<vector<int>> stones{{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};

    cout << removeStones(stones) << endl;

    return 0;
}
