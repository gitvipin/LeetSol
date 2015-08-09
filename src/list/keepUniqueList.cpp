void DelList(ListNode *head) {
    while (head) {
        ListNode *del = head;
        head = head->next;
        delete (del);
    }
}

ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next)
        return head;

    ListNode *prev, *curr;
    ListNode dummy(0);

    curr = head;
    prev = &dummy;

    while (curr) {
        // find the last node in the list which has same value as p1
        ListNode *del = curr;
        while ( del->next && del->val == del->next->val)
            del = del->next;
        if (curr == del) {
            prev->next = curr;
            prev = curr;
            curr = curr->next;
        } else {
            prev->next = del->next;
            del->next = NULL;
            DelList(curr);
            curr = prev->next;
        }
    }

    return dummy.next;
}
