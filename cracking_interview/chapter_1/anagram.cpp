#include <iostream>
#include <algorithm>

bool isAnagram(std::string s1, std::string s2) {
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());

    return s1 == s2;
}


int main() {
    std::string s1;
    std::string s2;

    std::cin >> s1 >> s2;

    std::cout << isAnagram(s1, s2) << std::endl;
}
