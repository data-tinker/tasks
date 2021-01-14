class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(begin(houses), end(houses));
        sort(begin(heaters), end(heaters));

        int maxRadius = numeric_limits<int>::min();

        for (size_t i = 0; i < houses.size(); ++i) {
            auto lower = lower_bound(begin(heaters), end(heaters), houses[i]);

            if (lower == begin(heaters)) {
                maxRadius = max(maxRadius, abs(houses[i] - *lower));
            } else if (lower == end(heaters)) {
                maxRadius = max(maxRadius, abs(houses[i] - heaters.back()));
            } else {
                maxRadius = max(
                    maxRadius,
                    min(
                        abs(houses[i] - *(lower - 1)),
                        abs(houses[i] - *lower)
                    )
                );
            }
        }

        return maxRadius;
    }
};
