#include <iostream>
#include <vector>

std::string TestCases[4] = {"aaa", "asd", "assdd", ""};

void removeDuplicates(std::string& s) {
    std::size_t idx = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        bool found = false;
        for (size_t j = 0; j < i; ++j) {
            if (s[j] == s[i]) {
                found = true;
            }
        }

        if (!found) {
            s[idx++] = s[i];
        }
    }

    s.resize(idx);
}

void removeDuplicatesWithDS(std::string &s) {
    std::vector<bool> seenCharacters(256, false);
    std::size_t idx = 0;

    for (const auto &c: s) {
        auto characterIdx = static_cast<int>(c);

        if (!seenCharacters[characterIdx]) {
            s[idx++] = c;
            seenCharacters[characterIdx] = true;
        }
    }

    s.resize(idx);
}

int main() {
    for (auto &testString: TestCases) {
        removeDuplicatesWithDS(testString);
        std::cout << testString << std::endl;
    }

    return 0;
}
