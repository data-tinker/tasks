#include <iostream>
#include "tree_node.h"

using namespace std;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == p || root == q || root == nullptr) {
        return root;
    }

    auto leftParent = lowestCommonAncestor(root->left, p, q);
    auto rightParent = lowestCommonAncestor(root->right, p, q);

    if (leftParent && rightParent) {
        return root;
    }

    return rightParent ? rightParent : leftParent;
}

int main() {
    auto head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->left->left = new TreeNode(3);
    head->left->right = new TreeNode(4);
    head->right = new TreeNode(5);

    cout << lowestCommonAncestor(head, head->left, head->right)->val << endl;

    return 0;
}
