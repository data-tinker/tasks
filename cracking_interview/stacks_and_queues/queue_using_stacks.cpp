#include <iostream>
#include <stack>

template <typename T>
class Queue {
public:
    void Push(T value) {
        InStack.push(value);
    }

    void Pop() {
        FillOutStack();

        OutStack.pop();
    }

    T Front() {
        FillOutStack();

        return OutStack.top();
    }
private:
    std::stack<T> InStack;
    std::stack<T> OutStack;

    void FillOutStack() {
        if (OutStack.empty()) {
            while (!InStack.empty()) {
                auto value = InStack.top();
                InStack.pop();
                OutStack.push(value);
            }
        }
    }
};

int main() {
    Queue<int> q;
    q.Push(1);
    q.Push(2);

    std::cout << q.Front() << std::endl;
    q.Pop();
    std::cout << q.Front() << std::endl;

    return 0;
}
