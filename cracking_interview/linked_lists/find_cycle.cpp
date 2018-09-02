#include <iostream>

struct LinkedListNode {
    int Data;
    LinkedListNode* Next;

    LinkedListNode(int data, LinkedListNode* next = nullptr)
        : Data(data)
        , Next(next)
    {}

    void PushBack(int data, LinkedListNode* next = nullptr) {
        auto currentNode = this;

        while (currentNode->Next) {
            currentNode = currentNode->Next;
        }

        currentNode->Next = new LinkedListNode(data, next);
    }
};

void printLinkedList(LinkedListNode* head) {
    auto currentNode = head;

    while (currentNode) {
        std::cout << currentNode->Data << ' ';
        currentNode = currentNode->Next;
    }

    std::cout << std::endl;
}

LinkedListNode* findCycleStart(LinkedListNode* head) {
    auto slowIterator = head;
    auto fastIterator = head;

    while (fastIterator) {
        slowIterator = slowIterator->Next;
        fastIterator = fastIterator->Next->Next;
        if (slowIterator == fastIterator) {
            break;
        }
    }

    if (fastIterator == nullptr) {
        return nullptr;
    }

    slowIterator = head;

    while (slowIterator != fastIterator) {
        slowIterator = slowIterator->Next;
        fastIterator = fastIterator->Next;
    }

    return fastIterator;
}

int main() {
    auto head = new LinkedListNode{1};
    head->PushBack(2);
    head->PushBack(3);
    head->PushBack(4);
    head->PushBack(5);
    head->PushBack(6);
    head->PushBack(7, head->Next->Next);

    std::cout << findCycleStart(head)->Data << std::endl;
};