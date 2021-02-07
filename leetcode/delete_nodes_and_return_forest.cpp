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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        queue<tuple<TreeNode*, TreeNode*, bool>> nodesQueue;
        unordered_set<int> toDelete(to_delete.begin(), to_delete.end());

        nodesQueue.emplace(root, nullptr, true);

        while (!nodesQueue.empty()) {
            auto [node, parent, add] = nodesQueue.front();
            nodesQueue.pop();

            if (toDelete.find(node->val) != toDelete.end()) {
                if (node->left) {
                    nodesQueue.emplace(node->left, node, true);
                }

                if (node->right) {
                    nodesQueue.emplace(node->right, node, true);
                }

                if (parent) {
                    if (parent->left == node) {
                        parent->left = nullptr;
                    } else {
                        parent->right = nullptr;
                    }
                    node = nullptr;
                    delete node;
                }
            } else {
                if (add) {
                    result.push_back(node);
                }

                if (node->left) {
                    nodesQueue.emplace(node->left, node, false);
                }

                if (node->right) {
                    nodesQueue.emplace(node->right, node, false);
                }
            }
        }

        return result;
    }
};
