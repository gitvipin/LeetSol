/*
Solution for : https://leetcode.com/problems/copy-list-with-random-pointer/
*/

RandomListNode *copyRandomList(RandomListNode *head) {

    if (!head)
        return NULL;

    RandomListNode dummy(0), *curr, *org;

    // Pass 1 : Create the new list and insert the elements in original list
    org = head;
    while (org) {
        RandomListNode * a = new RandomListNode(org->label);
        a->next = org->next;
        org->next = a;
        org = a->next;
    }

    // Pass 2 : Arrange the random pointers in the copy list
    org = head;
    while (org) {
        org->next->random = org->random ? org->random->next : NULL;
        org = org->next->next;
    }


    // Pass 3 : split the netlist
    org = head;
    curr = &dummy;
    while (org) {
        curr->next = org->next;
        org->next = org->next->next;

        curr = curr->next;
        org = org->next;
    }
    curr->next = NULL;
    return dummy.next;
}
