//https://leetcode.com/problems/intersection-of-two-linked-lists/

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA && headB) {
        ListNode *pA = headA;
        ListNode *pB = headB;

        while(pA && pB) {
            pA = pA->next;
            pB = pB->next;
        }

        // list A is longer
        while(pA) {
            headA = headA->next;
            pA = pA->next;
        }

        while(pB) {
            headB = headB->next;
            pB = pB->next;
        }

        // at this point both headA and headB sud have same number of elements
        while(1) {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
    }

    return NULL;
}
