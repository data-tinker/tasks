#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <tuple>
#include "tree_node.h"

using namespace std;

vector<vector<int>> binaryTreeToLinkedLists(TreeNode* root) {
    vector<vector<int>> result;
    queue<pair<size_t, TreeNode*>> bfs;
    size_t currentHeight = 0;

    bfs.push({1, root});

    while (!bfs.empty()) {
        auto [height, node] = bfs.front();
        bfs.pop();

        if (!node) {
            continue;
        }

        if (height > currentHeight) {
            result.emplace_back();
            currentHeight = height;
        }

        result.back().push_back(node->val);

        bfs.push({height + 1, node->left});
        bfs.push({height + 1, node->right});
    }

    return result;
}

int main() {
    auto head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4);
    head->right->right = new TreeNode(5);

    auto linkedLists = binaryTreeToLinkedLists(head);

    for (const auto& l: linkedLists) {
        for (auto n: l) {
            cout << n << ' ';
        }
        cout << endl;
    }

    return 0;
}
