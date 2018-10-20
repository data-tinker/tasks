#include <iostream>
#include <vector>
#include "tree_node.h"

using namespace std;

TreeNode* subarrayToBST(vector<int>::const_iterator b, vector<int>::const_iterator e) {
    if (b < e) {
        auto m = b + (e - b) / 2;

        auto node = new TreeNode(*m);
        node->left = subarrayToBST(b, m);
        node->right = subarrayToBST(m + 1, e);

        return node;
    }

    return nullptr;
}

TreeNode* sortedArrayToBST(const vector<int>& nums) {
    if (nums.empty()) {
        return nullptr;
    }

    return subarrayToBST(nums.cbegin(), nums.cend());
}

void inOrderPrint(TreeNode* node) {
    if (!node) {
        return;
    }

    inOrderPrint(node->left);
    cout << node->val << ' ';
    inOrderPrint(node->right);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    auto head = sortedArrayToBST(nums);

    inOrderPrint(head);

    return 0;
}
