/*
Solution for : https://leetcode.com/problems/intersection-of-two-linked-lists/
*/

/*
There are multiple ways to solve this problem. 

Soln (1) : Iterate over first list and for every element, check if it can be reached from second list. The first element that
can be reached is the intersection point. If no element can be reached there is no intersection. 
Time Complexity : O(n2) , Space Complexity : O(1)

Soln (2) :  Use extra memory and Hash the nodes in first list. While iterating over the second if in hash table node already exists. 
If node exists return the node which occurred first. Time : O(n+m) Space : O(m)

Soln (3) : If two lists are of same length, then two lists will hit the common element at the same time. This solution works on this idea.
Scan both lists, one node at a time. As soon as the shorter list exhausts, the longer one will have only the extra elements left
as unvisited. Now advance head pointer of the larger list until second list is also exhausted. After this, headA and headB both will point to
list of same lengths. Now scan again and return the node which is common between the two. 
Time Complexity : O(n+m), Space Complexity : O(1)

*/
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA && headB) {
        ListNode *pA = headA;
        ListNode *pB = headB;

        while(pA && pB) {
            pA = pA->next;
            pB = pB->next;
        }

        // list A is longer
        while(pA) {
            headA = headA->next;
            pA = pA->next;
        }

        while(pB) {
            headB = headB->next;
            pB = pB->next;
        }

        // at this point both headA and headB sud have same number of elements
        while(1) {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
    }

    return NULL;
}
