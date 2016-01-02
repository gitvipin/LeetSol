/*
solution for  : https://leetcode.com/problems/invert-binary-tree/
*/


/*
A simple DFS based, pre-order traversal of tree with swapping each of the left and right pointers of every node.
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
