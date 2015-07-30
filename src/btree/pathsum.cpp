// Solution for problem : https://leetcode.com/problems/path-sum/

bool hasPathSum(TreeNode* root, int sum) {
    if (!root) {
        return false;
    }

    if (!root->left && !root->right) {
        if (root->val == sum)
            return true;
        else
            return false;
    }

    if (hasPathSum(root->left, sum - root->val))
        return true;
    else
        return hasPathSum(root->right, sum - root->val);
}


