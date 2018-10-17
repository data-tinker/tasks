#include <iostream>
#include <stack>

template<typename T>
class MinStack {
public:
    void Push(T value) {
        Stack.push(value);
        if (MinValues.empty() || value <= MinValues.top()) {
            MinValues.push(value);
        }
    }

    T Top() const {
       return Stack.top();
    }

    void Pop() {
        auto value = Stack.top();
        Stack.pop();

        if (MinValues.top() == value) {
            MinValues.pop();
        }
    }

    T Min() const {
        return MinValues.top();
    }
private:
    std::stack<T> Stack;
    std::stack<T> MinValues;
};

int main() {
    MinStack<int> s;

    s.Push(3);
    std::cout << s.Min() << std::endl;

    s.Push(1);
    std::cout << s.Min() << std::endl;

    s.Pop();
    std::cout << s.Top() << std::endl;
    std::cout << s.Min() << std::endl;

    return 0;
}
