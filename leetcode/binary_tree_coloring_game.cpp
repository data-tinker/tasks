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
    TreeNode* findX(TreeNode* root, int x) {
        if (root->val == x) {
            return root;
        }

        TreeNode* found = nullptr;
        if (root->left) {
            found = findX(root->left, x);
        }
        if (!found && root->right) {
            found = findX(root->right, x);
        }
        return found;
    }

    int getSubtreeSize(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return 1 + getSubtreeSize(root->left) + getSubtreeSize(root->right);
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        auto startNode = findX(root, x);

        auto leftSubtreeSize = getSubtreeSize(startNode->left);
        auto rightSubtreeSize = getSubtreeSize(startNode->right);
        auto parentSubtreeSize = n - (leftSubtreeSize + rightSubtreeSize + 1);

        if (
            (leftSubtreeSize > rightSubtreeSize + 1 + parentSubtreeSize) ||
            (rightSubtreeSize > leftSubtreeSize + 1 + parentSubtreeSize) ||
            (parentSubtreeSize > leftSubtreeSize + 1 + rightSubtreeSize)
           ) {
            return true;
        }


        return false;
    }
};
