/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
private:
    Node* last = nullptr;
    Node* first = nullptr;

    void helper(Node* node) {
        if (!node) {
            return;
        }

        helper(node->left);

        if (first) {
            node->left = last;
            last->right = node;
        } else {
            first = node;
        }

        last = node;

        helper(node->right);
    }
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) {
            return nullptr;
        }

        helper(root);

        last->right = first;
        first->left = last;

        return first;
    }
};
