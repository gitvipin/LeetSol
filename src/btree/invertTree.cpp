/*
Problem : https://leetcode.com/problems/invert-binary-tree/
*/

TreeNode* invertTree(TreeNode* root) {
    if (!root)
        return NULL;

    TreeNode *left, *right;
    left = root->left;
    right = root->right;

    if (!left && !right)
        return root;

    root->left = right;
    root->right = left;

    if (left) invertTree(left);
    if (right) invertTree(right);

    return root;
}
