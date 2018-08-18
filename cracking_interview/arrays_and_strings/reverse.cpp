#include <iostream>
#include <cstring>

void reverse(char* s) {
    std::size_t left = 0;
    std::size_t right = std::strlen(s) - 1;

    while (left < right) {
        std::swap(s[left++], s[right--]);
    }
}

int main() {
    std::string s;
    std::cin >> s;

    reverse(&*s.begin());
    std::cout << s << std::endl;

    return 0;
}
