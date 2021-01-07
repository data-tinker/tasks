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
private:
    int diameterOfBinaryTreeHelper(TreeNode* root, int& result) {
        if (!root) {
            return 0;
        }

        int leftHeight = diameterOfBinaryTreeHelper(root->left, result);
        int rightHeight = diameterOfBinaryTreeHelper(root->right, result);

        result = max(result, leftHeight + rightHeight);

        return max(leftHeight, rightHeight) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        diameterOfBinaryTreeHelper(root, result);

        return result;
    }
};
