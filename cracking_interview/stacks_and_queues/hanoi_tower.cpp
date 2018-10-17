#include <iostream>
#include <stack>

using Pole = std::pair<std::string, std::stack<int>>;

void moveDisks(size_t disksCount, Pole& fromPole, Pole& toPole, Pole& withPole) {
    if (disksCount >= 1) {
        moveDisks(disksCount - 1, fromPole, withPole, toPole);

        auto disk = fromPole.second.top();

        std::cout << "Moving disk " << disk << " from pole " << fromPole.first << " to " << toPole.first << std::endl;
        toPole.second.push(disk);
        fromPole.second.pop();

        moveDisks(disksCount - 1, withPole, toPole, fromPole);
    }
}

int main() {
    Pole firstPole("A", std::stack<int>());
    Pole secondPole("B", std::stack<int>());
    Pole thirdPole("C", std::stack<int>());

    size_t n;
    std::cin >> n;

    for (size_t i = n; i >= 1; --i) {
        firstPole.second.push(i);
    }

    moveDisks(n, firstPole, thirdPole, secondPole);

    while (!thirdPole.second.empty()) {
        std::cout << thirdPole.second.top() << std::endl;
        thirdPole.second.pop();
    }

    return 0;
}
