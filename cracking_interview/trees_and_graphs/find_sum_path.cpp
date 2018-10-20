#include <iostream>
#include <vector>
#include "tree_node.h"

using namespace std;

void findSum(TreeNode* node, int sum, vector<int> buffer, int level) {
    if (!node) {
        return;
    }

    int tmp = sum;
    buffer.push_back(node->val);

    for (int i = level; i >= 0; --i) {
        tmp -= buffer[i];
        if (tmp == 0) {
            for (size_t j = i; j <= level; ++j) {
                cout << buffer[j] << ' ';
            }
            cout << endl;
        }
    }

    findSum(node->left, sum, buffer, level + 1);
    findSum(node->right, sum, buffer, level + 1);
}

int main() {
    auto head = new TreeNode(-10);
    head->left = new TreeNode(9);
    head->right = new TreeNode(20);
    head->right->left = new TreeNode(15);
    head->right->right = new TreeNode(7);

    vector<int> buffer;

    findSum(head, 35, buffer, 0);

    return 0;
}
