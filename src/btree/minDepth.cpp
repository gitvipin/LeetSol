/*
Solution for : https://leetcode.com/problems/minimum-depth-of-binary-tree/
TODO: Improve solution. Do not traverse further if you have seen a minimum depth already.
*/

int getMinDepth(TreeNode *root, int level) {
        if (!root)
            return level;
        else if (!root->left && !root->right) {
            return level + 1;
        } else if (root->left && root->right) {
            return std::min(getMinDepth(root->left, level+1),
                            getMinDepth(root->right, level +1));
        } else {
            if (root->left)
                return getMinDepth(root->left, level+1);
            else
                return getMinDepth(root->right, level+1);
                
        }
    }
    
    int minDepth(TreeNode* root) {
        return getMinDepth(root, 0);
    }
