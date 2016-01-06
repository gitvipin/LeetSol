
/*
Solution for : https://leetcode.com/problems/linked-list-cycle/
*/

/*
This problem can be solved in multiple ways. 

(1) Start traversing the Linked List. Keep hashing the nodes and if you find a node already hashed,
you have a cycle in the linked list. If you reach NULL without conflict, there is no cycle. 
Time Complexity : O(n)
Space Complexity : O(n)


(2) Use Fast pointer, slow pointer approach. Make a pointer run twice as fast as the other one, if the
both meet at some point, there is a loop in list 
Time Complexity : O(n)
Space Complexity : O(1)
*/

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
