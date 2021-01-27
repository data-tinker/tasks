struct Node {
    int idx;
    int path;
    int stops;

    bool operator<(const Node& other) const {
        return path == other.path ? stops > other.stops : path > other.path;
    }
};

class Solution {
private:
    int findCheapestPriceDijkstra(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& flight : flights) {
            graph[flight[0]].emplace_back(flight[1], flight[2]);
        }

        priority_queue<Node> pq;
        pq.push({src, 0, 0});

        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();

            if (node.idx == dst) {
                return node.path;
            }

            if (node.stops == k + 1) {
                continue;
            }

            for (const auto& [nb, weight] : graph[node.idx]) {
                pq.push({nb, node.path + weight, node.stops + 1});
            }
        }

        return -1;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        return findCheapestPriceDijkstra(n, flights, src, dst, k);
    }
};
