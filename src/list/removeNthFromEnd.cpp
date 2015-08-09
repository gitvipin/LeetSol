ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head || n <= 0)
        return head;

    ListNode *p, *q;
    p = q = head;

    // advance pointer p by n.
    while (n && p) {
        p = p->next;
        --n;
    }

    // if p exhausted and n is still not zero, n > list_length
    if (n)
        return head;
    else if (!p) {
        // First element has to be deleted
        head = head->next;
        delete q;
        return head;
    } else {
        // advance p so that q->next has to be deleted instead of q
        p = p->next;
    }

    while (p) {
        p = p->next;
        q = q->next;
    }

    p = q->next;
    q->next = (p) ? p->next : NULL;
    delete p;
    return head;
}
