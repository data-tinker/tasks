#include <stack>
#include <iostream>

void sortStack(std::stack<int>& s) {
    std::stack<int> helperStack;

    while (!s.empty()) {
        helperStack.push(s.top());
        s.pop();
    }

    while (!helperStack.empty()) {
        auto value = helperStack.top();
        helperStack.pop();

        while (!s.empty() && s.top() < value) {
            helperStack.push(s.top());
            s.pop();
        }
        s.push(value);
    }
}

int main() {
    std::stack<int> s;
    s.push(3);
    s.push(1);
    s.push(2);

    sortStack(s);

    while (!s.empty()) {
        std::cout << s.top() << std::endl;
        s.pop();
    }

    return 0;
}
