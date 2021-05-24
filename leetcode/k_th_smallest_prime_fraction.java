class Solution {
    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        int n = arr.length;
        PriorityQueue<Fraction> minHeap = new PriorityQueue<>();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                minHeap.add(new Fraction(arr[i], arr[j]));
            }
        }

        Fraction e = null;
        while (k != 0) {
            e = minHeap.poll();
            --k;
        }

        return new int[]{e.num, e.denom};
    }
}

class Fraction implements Comparable<Fraction> {
    int num;
    int denom;

    Fraction(int num, int denom) {
        this.num = num;
        this.denom = denom;
    }

    public int compareTo(Fraction other) {
        return this.num * other.denom - other.num * this.denom;
    }
}
