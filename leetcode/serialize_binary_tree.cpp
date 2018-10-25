#include <iostream>
#include <sstream>
#include "tree_node.h"

using namespace std;

void serializeDfs(TreeNode* root, string& serializedTree) {
    if (!root) {
        serializedTree += " null ";
        return;
    }

    serializedTree += " " + to_string(root->val) + " ";
    serializeDfs(root->left, serializedTree);
    serializeDfs(root->right, serializedTree);
}

string serialize(TreeNode* root) {
    string serializedTree = "";

    serializeDfs(root, serializedTree);

    return serializedTree;
}

TreeNode* deserializeDfs(istringstream& treeData) {
    string val;
    treeData >> val;

    if (val == "null") {
        return nullptr;
    }

    int ival = stoi(val);

    auto node = new TreeNode(ival);
    node->left = deserializeDfs(treeData);
    node->right = deserializeDfs(treeData);
    return node;
}

TreeNode* deserialize(string data) {
    istringstream treeData(data);

    return deserializeDfs(treeData);
}

int main() {
    auto head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->right->left = new TreeNode(4);
    head->right->right = new TreeNode(5);

    cout << deserialize(serialize(head))->val << endl;

    return 0;
}
