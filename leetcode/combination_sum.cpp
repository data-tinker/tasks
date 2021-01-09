class Solution {
private:
    void backtrack(vector<int>& candidates, int target, vector<int>& currentCombination, vector<vector<int>>& combinations, int currentSum, int currentIdx) {
        if (currentSum > target) {
            return;
        } else if (currentSum == target) {
            combinations.push_back(currentCombination);
        }

        for (size_t i = currentIdx; i < candidates.size(); ++i) {
            currentCombination.push_back(candidates[i]);
            backtrack(candidates, target, currentCombination, combinations, currentSum + candidates[i], i);
            currentCombination.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> currentCombination;
        vector<vector<int>> combinations;
        backtrack(candidates, target, currentCombination, combinations, 0, 0);

        return combinations;
    }
};
