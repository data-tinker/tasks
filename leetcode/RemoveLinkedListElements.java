public class RemoveLinkedListElements {
    class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    public ListNode removeElements(ListNode head, int val) {
        ListNode originalHead = head;
        ListNode previousHead = head;

        while (head != null) {
            if (head.val == val) {
                if (head == originalHead) {
                    originalHead = head.next;
                } else {
                    previousHead.next = head.next;
                }
            } else {
                previousHead = head;
            }

            head = head.next;

        }

        return originalHead;
    }

    public void printList(ListNode head) {
        while (head!= null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
    }

    public ListNode createList(int[] nums) {
        ListNode head = null;
        ListNode node = null;
        ListNode previous = null;

        for (int n : nums) {
            node = new ListNode(n);

            if (previous != null) {
                previous.next = node;
            } else {
                head = node;
            }

            previous = node;
        }

        return head;
    }


    public static void main(String[] args) {
        RemoveLinkedListElements solution = new RemoveLinkedListElements();
        ListNode head = solution.createList(new int[]{1,2,3,4});
        head = solution.removeElements(head, 2);
        solution.printList(head);
    }
}
