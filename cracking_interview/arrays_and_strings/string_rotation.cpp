#include <iostream>

bool isSubstring(std::string& baseString, std::string& subString) {
    return (baseString.find(subString) != std::string::npos);
}

int main() {
    std::string baseString, rotatedString;
    std::cin >> baseString >> rotatedString;

    if (baseString.length() != rotatedString.length()) {
        std::cout << false << std::endl;
        return 0;
    }

    auto concatenatedString = baseString + baseString;

    std::cout << isSubstring(concatenatedString, rotatedString) << std::endl;

    return 0;
}