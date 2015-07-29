
//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
TreeNode* findR(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (root == p || root == q)
        return root;
    if (p->val <= root->val && q->val >= root->val)
        return root;
    else if (root->val > p->val)
        return findR(root->left, p, q);
    else
        return findR(root->right, p, q);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || !p || !q)
        return NULL;
    else if (p->val > q->val)
        return findR(root, q, p);
    else
        return findR(root, p, q);
}

