/*
--------------------------------------------------------------------------------------
Problem : Delete nth node from end in the Linked List.
https://leetcode.com/problems/remove-nth-node-from-end-of-list/
--------------------------------------------------------------------------------------
*/

/* Solution 1: Use two pointers*/
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


/*
Solution 2 : Using two iterations. One to calculate the length of Linked List
and second to delete the node.
*/
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head || n < 0)
        return head;

    ListNode *h = head;
    int length = 0;
    while (h) {
        h = h->next;
        length++;
    }

    if (n > length)
        return head;

    /* If head has been asked to delete*/
    h = head;
    if (length == n) {
        head = head->next;
        delete h;
        return head;
    }

    n = length - n - 1;

    while (h) {
        if (!n) {
            ListNode *del = h->next;
            h->next = h->next->next;
            delete del;
            return head;
        }
        h = h->next;
        --n;
    }

}


