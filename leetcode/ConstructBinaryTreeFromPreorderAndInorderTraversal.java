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
    private int pIdx;

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        Map<Integer, Integer> inorderToPos = new HashMap<>();

        for (int i = 0; i < inorder.length; ++i) {
            inorderToPos.put(inorder[i], i);
        }

        return buildTreeHelper(preorder, 0, preorder.length - 1, inorderToPos);
    }

    private TreeNode buildTreeHelper(int[] preorder, int pStart, int pEnd, Map<Integer, Integer> inorderToPos) {
        if (pStart > pEnd) {
            return null;
        }

        int nodeVal = preorder[pIdx++];
        TreeNode node = new TreeNode(nodeVal);

        int newPivot = inorderToPos.get(nodeVal);

        node.left = buildTreeHelper(preorder, pStart, newPivot - 1, inorderToPos);
        node.right = buildTreeHelper(preorder, newPivot + 1, pEnd, inorderToPos);

        return node;
    }
}
