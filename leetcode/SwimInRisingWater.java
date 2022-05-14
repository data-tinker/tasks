class Solution {
    static final int[][] directions = {
        {0, -1},
        {-1, 0},
        {0, 1},
        {1, 0}
    };

    public int swimInWater(int[][] grid) {
        boolean[][] visited = new boolean[grid.length][grid.length];
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((lhs, rhs) -> Integer.compare(grid[lhs[0]][lhs[1]], grid[rhs[0]][rhs[1]]));

        pq.offer(new int[]{0, 0});
        visited[0][0] = true;
        int result = 0;

        while (!pq.isEmpty()) {
            int[] point = pq.poll();
            int y = point[0];
            int x = point[1];

            result = Math.max(result, grid[y][x]);

            if (y == grid.length - 1 && x == grid.length - 1) {
                return result;
            }

            for (int[] direction : directions) {
                int nbY = y + direction[0];
                int nbX = x + direction[1];

                if (nbY >= 0 && nbY < grid.length && nbX >= 0 && nbX < grid.length && !visited[nbY][nbX]) {
                    pq.offer(new int[]{nbY, nbX});
                    visited[nbY][nbX] = true;
                }
            }
        }

        return -1;
    }
}
