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
    int max = Integer.MIN_VALUE;

    private int maxPathSumHelper(TreeNode node) {
        if (node == null) {
            return 0;
        }

        int leftResult = Math.max(maxPathSumHelper(node.left), 0);
        int rightResult = Math.max(maxPathSumHelper(node.right), 0);

        max = Math.max(max, node.val + leftResult + rightResult);

        return node.val + Math.max(leftResult, rightResult);
    }

    public int maxPathSum(TreeNode root) {
        maxPathSumHelper(root);
        return max;
    }
}
