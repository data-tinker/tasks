/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        return deleteHelper(root, key);
    }

    private TreeNode deleteHelper(TreeNode node, int key) {
        if (node == null) {
            return null;
        }

        if (key < node.val) {
            node.left = deleteHelper(node.left, key);
        } else if (key > node.val) {
            node.right = deleteHelper(node.right, key);
        } else {
            if (node.left == null) {
                return node.right;
            } else if (node.right == null) {
                return node.left;
            }

            TreeNode minNode = min(node.right);
            node.val = minNode.val;
            node.right = deleteHelper(node.right, minNode.val);
        }

        return node;
    }

    private TreeNode min(TreeNode node) {
        if (node == null) {
            return null;
        } else if (node.left == null) {
            return node;
        }

        return min(node.left);
    }
}
