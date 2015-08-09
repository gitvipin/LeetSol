ListNode *reverseR(ListNode *head) {
    if (!head || !head->next)
        return head;
    ListNode *tmp = reverseR(head->next);
    head->next->next = head;
    head->next = NULL;
    return tmp;
}

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (!head || !head->next || m < 1 || n < m || m == n)
        return head;

    ListNode *p1, *p2, *p3;

    // set p1 and p2
    p2 = head;
    if ( m == 1) {
        p1 = NULL;
    } else {
        for ( int i = 1; i < m; i++) {
            if (i+1 == m)
                p1 = p2;
            p2 = p2->next;
        }
    }

    // set p3
    p3 = p2;
    for ( int i =m; i <n ; i++) {
        p3 = p3->next;
        if (i+1 == n) {
            ListNode *tmp = p3;
            p3 = p3->next;
            tmp->next = NULL;
        }
    }

    //reverse and merge list
    if (!p1)
        head = reverseR(p2);
    else
        p1->next = reverseR(p2);
    p2->next = p3;

    return head;
}
