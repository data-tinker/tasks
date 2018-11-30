#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v)
        : val(v)
        , left(nullptr)
        , right(nullptr)
    {}
};

bool validateBinarySearchTreeRecursive(TreeNode* node, long long Min, long long Max) {
    if (!node) {
        return true;
    }

    if (node->val <= Min || node->val >= Max) {
        return false;
    }

    return validateBinarySearchTreeRecursive(node->left, Min, node->val) &&
        validateBinarySearchTreeRecursive(node->right, node-> val, Max);
}

bool isValidBST(TreeNode* root) {
    return validateBinarySearchTreeRecursive(root, numeric_limits<long long>::min(), numeric_limits<long long>::max());
}

int main() {
    auto head = new TreeNode(3);
    head->left = new TreeNode(1);
    head->right = new TreeNode(1);

    cout << validateBinarySearchTree(head) << endl;

    return 0;
}
