
/*
--------------------------------------------------------
Problem : https://leetcode.com/problems/palindrome-linked-list/
--------------------------------------------------------
NOTE: Change the value of __RESTORE_LIST to 1 to have the netlist restored to original.
*/
#define __RESTORE_LIST	0

ListNode *reverseR(ListNode *head) {
    if (!head || !head->next)
        return head;
    ListNode *tmp = reverseR(head->next);
    head->next->next = head;
    head->next = NULL;
    return tmp;
}

bool isPalindrome(ListNode* head) {
    // check for special cases.
    if (!head || !head->next)
        return true;

    ListNode *p, *dp, *bkp;

    // find the middle point
    p = dp = head;
    while( p && dp) {
        p = p->next;    // increment single pointer once.

        dp = dp->next; //increment double pointer twice.
        if (dp)        // if possible.
            dp = dp->next;
    }

    // reverse the list here.
    bkp = dp = reverseR(p);
    p = head;

#if __RESTORE_LIST
    bool match = true;
    // traverse again and see if they match completely.
    while (p && dp) {
        if (match && p->val != dp->val)
            match = false;

        dp = dp->next;
        if (p->next) // dp should exhaust first.
            p = p->next;
    }

    // restore the netlist.
    if (p->next)
        p = p->next;
    //assert(!p->next); // enable only in debugging & validation mode.
    p->next = reverseR(bkp);

    return match;
#else
    while (p && dp) {
        if (p->val != dp->val)
            return false;
        p = p->next;
        dp = dp->next;
    }
    return true;
#endif
}
