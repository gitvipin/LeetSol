
/*
Solution for : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
*/


/*
EXPLAIN:
Tree is BST so when you reach a node 'r' such that p < r < q. r is the LCS for p and q. 
Now we have to descend the tree in right direction if both p and q are smaller or greater than the root.

NOTE: If we can maintain the order of p and q correctly such that p < q then our implementation can become very simple and lot of if-else
conditions can be eliminated. 

Time : O(logn) , Space : O(logn)  , stack space.
*/
TreeNode* findR(TreeNode* root, TreeNode* p, TreeNode* q)
{
    // if root matches p or q, it is the root.
    if (root == p || root == q)
        return root;
    // if  p <= root <= q , root is the answer else descend the tree.
    if (p->val <= root->val && q->val >= root->val)
        return root;
    else if (root->val > p->val)
        return findR(root->left, p, q);
    else
        return findR(root->right, p, q);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // put early checks and call findR with order of p and q corrected.
    if (!root || !p || !q)
        return NULL;
    else if (p->val > q->val)
        return findR(root, q, p);
    else
        return findR(root, p, q);
}

