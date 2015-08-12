/*
Solution for problem : https://leetcode.com/problems/reorder-list/
*/

ListNode *reverseR(ListNode *head) {
    if (!head || !head->next)
        return head;

    ListNode *tmp = reverseR(head->next);
    head->next->next = head;
    head->next = NULL;
    return tmp;
}


void reorderList(ListNode* head) {
    // upto 2 length list is already in right order
    if ( !head || !head->next || !head->next->next)
        return;

    // find the middle of the list
    ListNode *pslow, *pfast;
    pslow = pfast = head;

    while (pfast && pfast->next) {
        pslow = pslow->next;
        pfast = pfast->next->next;
    }

    // reverse the second half
    // TODO : improve this to 3 pointer reverse to save on space complexity
    pfast = reverseR(pslow->next);
    pslow->next = NULL;

    // now merge the lists
    pslow = head;
    ListNode dummy(0), *curr;
    curr = &dummy;

    while (pslow && pfast) {
        ListNode *p1 = pslow;
        ListNode *p2 = pfast;

        pslow = pslow->next;
        pfast = pfast->next;

        curr->next = p1;
        curr = curr->next;
        curr->next = p2;
        curr = curr->next;
    }

    curr->next = (pslow) ? pslow : pfast;

    head = dummy.next;
}
