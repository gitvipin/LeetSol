/*
--------------------------------------------------------------------------------------
Solution : Remove duplicates from Sorted Linked List
https://leetcode.com/problems/remove-duplicates-from-sorted-list/
--------------------------------------------------------------------------------------
*/
ListNode* deleteDuplicates(ListNode* head) {
    ListNode *ret = head;
    while (head) {
        // must check for head->next to avoid segmentation fault.
        if (head->next && head->val == head->next->val) {
            ListNode *del = head->next;
            head->next = del->next;
            delete del;
        } else {
            head = head->next;
        }
    }
    return ret;
}
