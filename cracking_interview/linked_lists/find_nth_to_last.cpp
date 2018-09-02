#include <iostream>
#include "linked_list.h"

using namespace NLinkedList;

int main() {
    int n, position, value;
    LinkedList<int> llist;

    std::cin >> n >> position;

    for (size_t i = 0; i < n; ++i) {
        std::cin >> value;
        llist.PushBack(value);
    }

    if (position > llist.Size() - 1) {
        std::cout << llist.GetHead()->Data << std::endl;
        return 0;
    }

    auto leftIter = llist.GetHead();
    auto rightIter = llist.GetHead();

    for (size_t i = 0; i < position; ++i) {
        rightIter = rightIter->Next.get();
    }

    while (rightIter->Next) {
        rightIter = rightIter->Next.get();
        leftIter = leftIter->Next.get();
    }

    std::cout << leftIter->Data << std::endl;

    return 0;
}