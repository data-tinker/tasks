class Solution {
    private boolean checkDay(int[] bloomDay, int m, int k, int day) {
        int numberOfBouquets = 0;
        int currentBouquet = 0;

        for (int flower: bloomDay) {
            if (flower <= day) {
                ++currentBouquet;
                if (currentBouquet == k) {
                    ++numberOfBouquets;
                    currentBouquet = 0;
                }
            } else {
                currentBouquet = 0;
            }
        }

        if (numberOfBouquets >= m) {
            return true;
        }

        return false;
    }

    public int minDays(int[] bloomDay, int m, int k) {
        int r = 1_000_000_000;
        int l = 0;

        while (l < r) {
            int med = (l + r) / 2;

            boolean canMakeBouquet = checkDay(bloomDay, m, k, med);

            if (canMakeBouquet) {
                r = med;
            } else {
                l = med + 1;
            }
        }

        if (checkDay(bloomDay, m, k, l)) {
            return l;
        }

        return -1;
    }
}
