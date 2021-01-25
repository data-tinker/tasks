/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*, int>> nodesQueue;

        int currentLevel = 1;
        int maxLevel = numeric_limits<int>::min();

        int currentSum = 0;
        int maxSum = numeric_limits<int>::min();

        nodesQueue.emplace(root, 1);

        while (!nodesQueue.empty()) {
            auto [node, level] = nodesQueue.front();
            nodesQueue.pop();

            if (level > currentLevel) {
                if (currentSum > maxSum) {
                    maxLevel = currentLevel;
                    maxSum = currentSum;
                }

                currentLevel = level;
                currentSum = 0;
            }

            currentSum += node->val;
            if (node->left) {
                nodesQueue.emplace(node->left, currentLevel + 1);
            }

            if (node->right) {
                nodesQueue.emplace(node->right, currentLevel + 1);
            }
        }

        if (currentSum > maxSum) {
            maxLevel = currentLevel;
        }

        return maxLevel;
    }
};
