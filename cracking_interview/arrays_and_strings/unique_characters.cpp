#include <iostream>
#include <string>
#include <vector>


bool AllCharactersUnique(const std::string &inputString) {
    std::vector<bool> characterMet(256, false);
    for (const auto &character: inputString) {
        auto index = static_cast<uint8_t>(character);

        if (characterMet[index]) {
            return false;
        }

        characterMet[index] = true;
    }

    return true;
}


int main() {
    std::string inputString;
    std::cin >> inputString;
    std::cout << AllCharactersUnique(inputString) << std::endl;
}
