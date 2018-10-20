#include <iostream>
#include "tree_node.h"

using namespace std;

int height(TreeNode* node) {
    if (!node) {
        return 0;
    }

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
        return -1;
    }

    return 1 + max(leftHeight, rightHeight);
}


bool isBalanced(TreeNode* root) {
    return height(root) != -1;
}

int main() {
    TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->left->left = new TreeNode(3);

    tree->right = new TreeNode(2);
    tree->right->right = new TreeNode(3);

    cout << isBalanced(tree) << endl;

    return 0;
}
