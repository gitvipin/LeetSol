/*
Solution for Problem: https://leetcode.com/problems/delete-node-in-a-linked-list/
Delete any but last node in Linked List.
*/

void deleteNode(ListNode* node) {
        if (!node || !node->next)
            return;
        ListNode *del = node->next;
        
        node->val = del->val;
        node->next = del->next;
        
        delete del;
    }
