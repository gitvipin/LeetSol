/*
Solution to problem : https://leetcode.com/problems/swap-nodes-in-pairs/
*/

ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next)
        return head;

    ListNode dummy(0), *curr;

    dummy.next = head;
    curr = &dummy;

    while (curr && curr->next && curr->next->next) {
        ListNode *tmp = curr->next;

        head = tmp->next->next;
        curr->next = tmp->next;
        curr->next->next = tmp;
        tmp->next = head;
        curr = tmp;
    }

    return dummy.next;
}
