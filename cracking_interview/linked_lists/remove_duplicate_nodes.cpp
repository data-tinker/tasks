#include <iostream>
#include <unordered_set>
#include "linked_list.h"

using namespace NLinkedList;

void removeDuplicatesDS(LinkedList<int>& llist) {
    std::unordered_set<int> usedValues;

    LinkedList<int>::LinkedListNode* previousNode = nullptr;
    auto currentNode = llist.GetHead();

    while (currentNode) {
        if (usedValues.find(currentNode->Data) != usedValues.end()) {
            previousNode->Next = std::move(currentNode->Next);
            currentNode = previousNode->Next.get();
        } else {
            previousNode = currentNode;
            usedValues.insert(currentNode->Data);
            currentNode = currentNode->Next.get();
        }
    }
}

void removeDuplicatesIter(LinkedList<int>& llist) {
    LinkedList<int>::LinkedListNode* previousNode = nullptr;
    auto currentNode = llist.GetHead();

    while (currentNode) {
        auto iter = llist.GetHead();

        while (iter != currentNode) {
            if (iter->Data == currentNode->Data) {
                previousNode->Next = std::move(currentNode->Next);
                currentNode = previousNode->Next.get();
                break;
            }

            iter = iter->Next.get();
        }

        if (iter == currentNode) {
            previousNode = currentNode;
            currentNode = currentNode->Next.get();
        }
    }
}

int main() {
    int n, v;
    std::cin >> n;

    LinkedList<int> llist;

    for (size_t i = 0; i < n; ++i) {
        std::cin >> v;
        llist.PushBack(v);
    }

    removeDuplicatesIter(llist);

    for (const auto& node: llist) {
        std::cout << node.Data << std::endl;
    }

    return 0;
}
