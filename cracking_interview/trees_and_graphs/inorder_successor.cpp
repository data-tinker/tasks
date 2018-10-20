#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
        , parent(nullptr)
    {}
};

TreeNode* addNode(int val, TreeNode* parentNode, TreeNode* node) {
    if (!node) {
        node = new TreeNode(val);
        node->parent = parentNode;
    } else if (val < node->val) {
        node->left = addNode(val, node, node->left);
    } else if (val > node->val) {
        node->right = addNode(val, node, node->right);
    }

    return node;
}

TreeNode* leftmostChild(TreeNode* node) {
    if (!node) {
        return nullptr;
    }

    while (node->left) {
        node = node->left;
    }

    return node;
}

TreeNode* inorderSuccessor(TreeNode* node) {
    if (!node) {
        return nullptr;
    }

    if (!node->parent || node->right) {
        return leftmostChild(node->right);
    }

    while (node->parent) {
        if (node->parent->left == node) {
            return node->parent;
        }

        node = node->parent;
    }

    return nullptr;
}

int main() {
    auto head = new TreeNode(4);
    addNode(2, head, head);
    addNode(3, head, head);
    addNode(1, head, head);
    addNode(5, head, head);

    cout << inorderSuccessor(head->left->right)->val << endl;

    return 0;
}
