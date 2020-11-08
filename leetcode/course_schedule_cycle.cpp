class Solution {
private:
    enum States {
        NOT_VISITED,
        VISITING,
        VISITED,
    };
public:
    bool hasCycle(const vector<vector<int>>& graph, vector<States>& states, int startVertex) {
        bool cycle = false;
        states[startVertex] = VISITING;

        for (auto adj: graph[startVertex]) {
            if (states[adj] == VISITING) {
                return true;
            } else if (states[adj] == NOT_VISITED) {
                cycle |= hasCycle(graph, states, adj);
            }
        }

        states[startVertex] = VISITED;

        return cycle;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (size_t i = 0; i < prerequisites.size(); ++i) {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<States> states(numCourses, NOT_VISITED);

        for (size_t i = 0; i < states.size(); ++i) {
            if (states[i] == NOT_VISITED) {
                if (hasCycle(graph, states, i)) {
                    return false;
                }
            }
        }

        return true;
    }
};
