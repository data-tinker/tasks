#include <iostream>
#include <stack>
#include <vector>
#include <cassert>

template <typename T>
class SetOfStacks {
public:
    SetOfStacks(const size_t maxSize)
        : MaxSize(maxSize)
        , Stacks(1)
    {}

    void Push(T value) {
        if (Stacks.back().size() == MaxSize) {
            Stacks.push_back(std::stack<T>());
        }

        Stacks.back().push(value);
    }

    T Top() const {
        return Stacks.back().top();
    }

    void Pop() {
        Stacks.back().pop();

        if (Stacks.back().empty()) {
            Stacks.pop_back();
        }
    }

    void PopAt(size_t idx) {
        Stacks[idx].pop();

        if (Stacks[idx].empty()) {
            Stacks.erase(Stacks.begin() + idx);
        }
    }
private:
    size_t MaxSize;
    std::vector<std::stack<T>> Stacks;
};


int main() {
    SetOfStacks<int> s(1);

    s.Push(1);
    s.Push(2);
    s.Push(3);

    s.PopAt(2);
    std::cout << s.Top() << std::endl;

    s.Push(3);
    std::cout << s.Top() << std::endl;

    return 0;
}
