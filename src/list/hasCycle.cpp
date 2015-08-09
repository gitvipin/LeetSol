bool hasCycle(ListNode *head) {
    if (!head)
        return false;

    ListNode *pSlow, *pFast;

    pSlow = pFast = head;

    while ( pSlow && pFast && pFast->next) {
        pSlow = pSlow->next;
        pFast = pFast->next->next;
        if (pSlow == pFast) {
            return true;
        }
    }
    return false;

}
