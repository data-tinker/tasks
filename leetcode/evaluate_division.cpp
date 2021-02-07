class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;

        for (size_t i = 0; i < equations.size(); ++i) {
            graph[equations[i][0]].emplace_back(equations[i][1], values[i]);
            graph[equations[i][1]].emplace_back(equations[i][0], 1.0 / values[i]);
        }

        vector<double> result;
        for (const auto& query : queries) {
            string start = query[0];
            string end = query[1];

            if (graph.find(start) == graph.end()) {
                result.push_back(-1);
                continue;
            }

            stack<pair<string, double>> variableToCost;
            unordered_set<string> visited;

            variableToCost.emplace(start, 1);
            visited.insert(start);
            double resultCost = -1;

            while (!variableToCost.empty()) {
                auto [variable, cost] = variableToCost.top();
                variableToCost.pop();

                if (variable == end) {
                    resultCost = cost;
                    break;
                }

                for (const auto& path : graph[variable]) {
                    if (visited.find(path.first) == visited.end()) {
                        variableToCost.emplace(path.first, cost * path.second);
                        visited.insert(variable);
                    }
                }
            }

            result.push_back(resultCost);
        }

        return result;
    }
};
