/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* reverseListIterative(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode* prev = nullptr;
        ListNode* next = head->next;

        while (head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

    ListNode* reverseListRecursive(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        auto next = reverseListRecursive(head->next);
        head->next->next = head;
        head->next = nullptr;

        return next;
    }
public:
    ListNode* reverseList(ListNode* head) {
        return reverseListRecursive(head);
    }
};
