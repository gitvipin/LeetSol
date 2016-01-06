/*
Solution for : https://leetcode.com/problems/linked-list-cycle-ii/
*/


/*
(1) First detect the loop.

 If loop is there
 (2) Find length of the loop
 (3) Now move on pointer "length" times from "head"
 (4) When one pointer has moved , length from head start another from head. 
 (5) Place where they both meet is the head of the loop
*/

ListNode *getLoopHead(ListNode *head, ListNode *pLoop) {
    ListNode *p1, *p2;
    int length = 1;

    // get Loop length
    p1 = p2 = pLoop;
    while(p1->next != p2) {
        length++;
        p1 = p1->next;
    }

    p1 = p2 = head;
    while (length) {
        p2 = p2->next;
        length--;
    }

    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p1;
}

ListNode *detectCycle(ListNode *head) {
    if (!head)
        return NULL;

    ListNode *pSlow, *pFast;

    pSlow = pFast = head;

    while ( pSlow && pFast && pFast->next) {
        pSlow = pSlow->next;
        pFast = pFast->next->next;
        if (pSlow == pFast) {
            return getLoopHead(head, pSlow);
        }
    }
    return NULL;
}
