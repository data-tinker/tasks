class Solution {
public:
    string getHint(string secret, string guess) {
        int bullsNumber = 0;
        int cowsNumber = 0;

        array<int, 10> digitCountSecret = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        array<int, 10> digitCountGuess = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        for (size_t i = 0; i < secret.length(); ++i) {
            if (secret[i] == guess[i]) {
                ++bullsNumber;
            } else {
                ++digitCountSecret[secret[i] - '0'];
                ++digitCountGuess[guess[i] - '0'];
            }
        }

        for (size_t i = 0; i < 10; ++i) {
            cowsNumber += min(digitCountSecret[i], digitCountGuess[i]);
        }

        return to_string(bullsNumber) + "A" + to_string(cowsNumber) + "B";
    }
};
