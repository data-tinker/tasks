class Solution {
private:
    struct Worker {
        int quality;
        int wage;
        double ratio;

        Worker(int quality, int wage)
            : quality(quality)
            , wage(wage)
        {
            ratio = static_cast<double>(wage) / quality;
        }

        bool operator<(const Worker& other) const {
            return ratio < other.ratio;
        }
    };
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<Worker> workers;

        for (size_t i = 0; i < quality.size(); ++i) {
            workers.push_back({quality[i], wage[i]});
        }

        sort(begin(workers), end(workers));
        priority_queue<int> workersQueue;

        int sumQueue = 0;
        double result = numeric_limits<double>::max();
        for (const auto& worker: workers) {
            workersQueue.push(worker.quality);
            sumQueue += worker.quality;
            if (workersQueue.size() > K) {
                sumQueue -= workersQueue.top();
                workersQueue.pop();
            }

            if (workersQueue.size() == K) {
                result = min(result, worker.ratio * sumQueue);
            }
        }

        return result;
    }
};
