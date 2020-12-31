class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) {
            return false;
        }

        int sum = 1;

        for (size_t i = 2; i < sqrt(num); ++i) {
            if (num % i == 0) {
                sum += (i + num / i);
            }
        }

        return num == sum;
    }
};
