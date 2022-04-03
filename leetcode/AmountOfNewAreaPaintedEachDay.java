class PaintedSegmentTree {
  int[] cache;
  int[] sum;
  int limit;

  PaintedSegmentTree(int limit) {
    this.limit = limit;
    cache = new int[limit * 4];
    sum = new int[limit * 4];
  }

  public void update(int start, int end) {
    updateTree(start, end, 1, 0, limit - 1);
  }

  public int query(int start, int end) {
    return queryTree(start, end, 1, 0, limit - 1);
  }

  private void updateTree(int start, int end, int idx, int segmentStart, int segmentEnd) {
    if (start > end) {
      return;
    }
    if (start == segmentStart && end == segmentEnd) {
      sum[idx] = segmentEnd - segmentStart + 1;
      cache[idx] = 1;
      return;
    }
    int middle = (segmentStart + segmentEnd) / 2;

    updateTree(start, Math.min(end, middle), 2 * idx, segmentStart, middle);
    updateTree(Math.max(start, middle + 1), end, 2 * idx + 1, middle + 1, segmentEnd);

    sum[idx] = sum[2 * idx] + sum[2 * idx + 1];
  }

  private int queryTree(int start, int end, int idx, int segmentStart, int segmentEnd) {
    updateSegment(idx, segmentStart, segmentEnd);
    if (start > end) {
      return 0;
    }
    if (start == segmentStart && end == segmentEnd) {
      return sum[idx];
    }

    int middle = (segmentStart + segmentEnd) / 2;

    return queryTree(start, Math.min(end, middle), 2 * idx, segmentStart, middle) +
        queryTree(Math.max(start, middle + 1), end, 2 * idx + 1, middle + 1, segmentEnd);
  }

  private void updateSegment(int idx, int segmentStart, int segmentEnd) {
    if (cache[idx] == 0 || segmentStart == segmentEnd) {
      return;
    }
    int middle = (segmentStart + segmentEnd) / 2;

    cache[2 * idx] = cache[2 * idx + 1] = 1;
    sum[2 * idx] = middle - segmentStart + 1;
    sum[2 * idx + 1] = segmentEnd - middle;
    cache[idx] = 0;
  }
}

class Solution {
    public int[] amountPainted(int[][] paint) {
      PaintedSegmentTree tree = new PaintedSegmentTree(5 * 10000);
      int[] result = new int[paint.length];
      for (int i = 0; i < paint.length; ++i) {
        int left = paint[i][0];
        int right = paint[i][1];
        result[i] = right - left - tree.query(left, right - 1);
        tree.update(left, right - 1);
      }
      return result;
    }
}
