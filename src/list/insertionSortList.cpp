ListNode* insertionSortList(ListNode* head) {
    if (!head || !head->next)
        return head;

    ListNode *slist, *ulist;

    slist = head;   // sorted list
    ulist = head->next; // unsorted list

    head->next = NULL;

    while (ulist) {// until the unsorted list is finished.
        ListNode    *p = slist;
        ListNode    *unext = ulist->next;

        if (ulist->val < p->val) { // Insert in the beginning
            ulist->next = slist;
            slist = ulist;
        } else {
            // insert in the middle or in the end.
            while (p->next && ulist->val >= p->next->val)
                p = p->next;
            ulist->next = p->next;
            p->next = ulist;
        }

        ulist = unext;  //advance unsorted list
    }

    return slist;
}
