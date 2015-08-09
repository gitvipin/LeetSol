ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1)
        return l2;
    else if (!l2)
        return l1;

    ListNode *head, *last, *curr;
    head = last = curr = NULL;
    if (l1->val < l2->val) {
        last = l1;
        l1 = l1->next;
    } else {
        last = l2;
        l2 = l2->next;
    }
    head = last;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            last->next = l1;
            l1 = l1->next;
        } else {
            last->next = l2;
            l2 = l2->next;
        }
        last = last->next;
    }

    last->next = l1 ? l1 : l2;
    return head;
}
