#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool isValid(const string& s) {
    stack<char> pStack;
    unordered_map<char, char> openToClose = {
        {'(', ')'}, {'{', '}'}, {'[', ']'}
    };
    unordered_map<char, char> closeToOpen = {
        {')', '('}, {'}', '{'}, {']', '['}
    };

    for (auto c: s) {
        if (openToClose.find(c) != openToClose.end()) {
            pStack.push(c);
        } else {
            if (pStack.empty()) {
                return false;
            }

            auto prevOpen = pStack.top();
            pStack.pop();

            if (closeToOpen[c] != prevOpen) {
                return false;
            }
        }
    }

    if (!pStack.empty()) {
        return false;
    }

    return true;
}

int main() {
    cout << isValid("(())") << endl;

    return 0;
}
