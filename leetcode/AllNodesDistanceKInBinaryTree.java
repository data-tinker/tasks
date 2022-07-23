/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        var graph = createGraph(root);

        return bfs(target.val, graph, k);
    }

    private Map<Integer, List<Integer>> createGraph(TreeNode root) {
        var graph = new HashMap<Integer, List<Integer>>();

        var queue = new ArrayDeque<TreeNode>();
        queue.add(root);

        while (!queue.isEmpty()) {
            var node = queue.poll();

            var nbs = graph.getOrDefault(node.val, new ArrayList<Integer>());

            if (node.left != null) {
                queue.add(node.left);
                nbs.add(node.left.val);
                graph.put(node.left.val, Stream.of(node.val).collect(Collectors.toList()));
            }

            if (node.right != null) {
                queue.add(node.right);
                nbs.add(node.right.val);
                graph.put(node.right.val, Stream.of(node.val).collect(Collectors.toList()));
            }

           graph.put(node.val, nbs);
        }

         return graph;
    }

    private List<Integer> bfs(int startNode, Map<Integer, List<Integer>> graph, int k) {
        var queue = new ArrayDeque<Integer>();
        var visited = new HashSet<Integer>();
        var result = new ArrayList<Integer>();

        queue.add(startNode);
        visited.add(startNode);
        int currentK = 0;

        while (!queue.isEmpty()) {
            var n = queue.size();

            while (n > 0) {
                var node = queue.poll();

                if (currentK == k) {
                    result.add(node);
                }

                var nbs = graph.get(node);

                for (var nb : nbs) {
                    if (!visited.contains(nb)) {
                        queue.add(nb);
                        visited.add(nb);
                    }
                }
                --n;
            }

            ++currentK;
        }

        return result;
    }

}
