/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode skipPointer = head;

        if (head == null) {
            return false;
        }

        while (head.next != null) {
            head = head.next;

            if (skipPointer != null && skipPointer.next != null) {
                skipPointer = skipPointer.next;
                skipPointer = skipPointer.next;

                if (skipPointer == head) {
                    return true;
                }
            }
        }

        return false;
    }
}
