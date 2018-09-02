#include <iostream>
#include "linked_list.h"

using namespace NLinkedList;

LinkedList<int> sumLinkedLists(LinkedList<int>& llist1, LinkedList<int>& llist2) {
    LinkedList<int> resultLlist;

    auto head1 = llist1.GetHead();
    auto head2 = llist2.GetHead();
    bool carryover = false;

    while (head1 || head2) {
        if (head1 && head2) {
            auto sum = head1->Data + head2->Data;

            if (carryover) {
                ++sum;
            }

            if (sum >= 10) {
                carryover = true;
                sum %= 10;
            } else {
                carryover = false;
            }

            resultLlist.PushBack(sum);

            head1 = head1->Next.get();
            head2 = head2->Next.get();
        } else if (head1) {
            if (carryover) {
                resultLlist.PushBack(head1->Data + 1);
                carryover = false;
            } else {
                resultLlist.PushBack(head1->Data);
            }
            head1 = head1->Next.get();
        } else {
            if (carryover) {
                resultLlist.PushBack(head2->Data + 1);
                carryover = false;
            } else {
                resultLlist.PushBack(head2->Data);
            }
            head2 = head2->Next.get();
        }
    }

    return resultLlist;
}

int main() {
    int n, value;
    size_t position;
    LinkedList<int> llist1{};
    LinkedList<int> llist2{5, 9, 2};

    auto llist = sumLinkedLists(llist1, llist2);

    for (const auto& node: llist) {
        std::cout << node.Data << std::endl;
    }

    return 0;
}