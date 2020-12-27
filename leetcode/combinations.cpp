class Solution {
public:
    void backtrack(vector<vector<int>>& combinations, vector<int>& combination, int n, int k, size_t idx) {
        if (combination.size() == k) {
            combinations.push_back(combination);
            return;
        }

        for (size_t i = idx; i < n + 1; ++i) {
            combination.push_back(i);
            backtrack(combinations, combination, n, k, i + 1);
            combination.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> numbers;

        vector<vector<int>> combinations;
        vector<int> combination;

        backtrack(combinations, combination, n, k, 1);

        return combinations;
    }
};
