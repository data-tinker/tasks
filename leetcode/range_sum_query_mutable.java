class NumArray {
    int[] tree;
    int n;

    public NumArray(int[] nums) {
        if (nums.length > 0) {
            n = nums.length;
            tree = new int[n * 4];
            buildTree(nums, 1, 0, n - 1);
        }

        System.out.println(Arrays.toString(tree));
    }

    private void buildTree(int[] nums, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = nums[tl];
        } else {
            int m = (tl + tr) / 2;
            buildTree(nums, v * 2, tl, m);
            buildTree(nums, v * 2 + 1, m + 1, tr);
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    }

    public void update(int index, int val) {
        updateTree(1, 0, n - 1, index, val);
    }

    private void updateTree(int v, int tl, int tr, int index, int val) {
        if (tl == tr) {
            tree[v] = val;
        } else {
            int m = (tl + tr) / 2;
            if (index <= m) {
                updateTree(v * 2, tl, m, index, val);
            } else {
                updateTree(v * 2 + 1, m + 1, tr, index, val);
            }
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    }

    public int sumRange(int left, int right) {
        return sumRangeTree(1, 0, n - 1, left, right);
    }

    private int sumRangeTree(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == tl && r == tr) {
            return tree[v];
        }
        int m = (tl + tr) / 2;
        return sumRangeTree(v * 2, tl, m, l, Math.min(r, m)) + sumRangeTree(v * 2 + 1, m + 1, tr, Math.max(l, m + 1), r);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */
