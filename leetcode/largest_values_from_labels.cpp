class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        unordered_map<int, multiset<int, greater<int>>> labelsToValues;
        vector<int> bestValues;

        for (size_t i = 0; i < labels.size(); ++i) {
            labelsToValues[labels[i]].insert(values[i]);
        }

        for (const auto& pair : labelsToValues) {
            int remainigElements = use_limit;
            for (const auto num : pair.second) {
                if (remainigElements-- == 0) {
                    break;
                }
                bestValues.push_back(num);
            }
        }

        sort(begin(bestValues), end(bestValues), greater<>());

        int result = 0;
        for (size_t i = 0; i < min(num_wanted, static_cast<int>(bestValues.size())); ++i) {
            result += bestValues[i];
        }

        return result;
    }
};
