#include <iostream>
#include "linked_list.h"

using namespace NLinkedList;

int main() {
    int n, value;
    size_t position;
    LinkedList<int> llist;

    std::cin >> n >> position;
    --position;

    for (size_t i = 0; i < n; ++i) {
        std::cin >> value;
        llist.PushBack(value);
    }

    llist.Erase(position);

    for (const auto& node: llist) {
        std::cout << node.Data << std::endl;
    }

    return 0;
}