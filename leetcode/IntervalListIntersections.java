class Point {
    private int coordinate;
    private boolean start;

    Point(int coordinate, boolean start) {
        this.coordinate = coordinate;
        this.start = start;
    }

    public int getCoordinate() {
        return coordinate;
    }

    public boolean isStart() {
        return start;
    }
}

class Solution {
    public int[][] intervalIntersectionSort(int[][] firstList, int[][] secondList) {
        List<Point> points = new ArrayList<>();
        initPoints(firstList, points);
        initPoints(secondList, points);

        Collections.sort(points, (lhs, rhs) -> {
            if (lhs.getCoordinate() == rhs.getCoordinate()) {
                return Boolean.compare(rhs.isStart(), lhs.isStart());
            }

            return Integer.compare(lhs.getCoordinate(), rhs.getCoordinate());
        });

        List<List<Integer>> result = new ArrayList<>();
        int overlappingIntervals = 0;
        for (Point point : points) {
            if (point.isStart()) {
                ++overlappingIntervals;

                if (overlappingIntervals == 2) {
                    result.add(new ArrayList());
                    result.get(result.size() - 1).add(point.getCoordinate());
                }
            } else {
                --overlappingIntervals;

                if (overlappingIntervals == 1) {
                    result.get(result.size() - 1).add(point.getCoordinate());
                }
            }
        }

        return result.stream()
            .map(interval -> interval.stream().mapToInt(i -> i).toArray())
            .toArray(int[][]::new);
    }

    private void initPoints(int[][] list, List<Point> points) {
        for (int i = 0; i < list.length; ++i) {
            points.add(new Point(list[i][0], true));
            points.add(new Point(list[i][1], false));
        }
    }

    public int[][] intervalIntersection(int[][] A, int[][] B) {
        List<int[]> result = new ArrayList();
        int i = 0, j = 0;

        while (i < A.length && j < B.length) {
            int lo = Math.max(A[i][0], B[j][0]);
            int hi = Math.min(A[i][1], B[j][1]);

            if (lo <= hi) {
                result.add(new int[]{lo, hi});
            }

            if (A[i][1] < B[j][1]) {
                ++i;
            } else {
                ++j;
            }
        }

        return result.toArray(new int[result.size()][]);
    }
}
