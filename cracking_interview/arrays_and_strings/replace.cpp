#include <iostream>

void replace(std::string& s, const std::string& replaceWhat, const std::string& replaceWith) {
    std::size_t idx = 0;

    while ((idx = s.find(replaceWhat, idx)) != std::string::npos) {
        s.replace(idx, replaceWhat.size(), replaceWith);
        idx += replaceWith.size();
    }
}

int main() {
    std::string s;
    std::getline(std::cin, s);

    replace(s, " ", "%20");

    std::cout << s << std::endl;

    return 0;
}
