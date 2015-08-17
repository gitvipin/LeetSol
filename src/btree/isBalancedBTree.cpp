/*
Solution for : https://leetcode.com/problems/balanced-binary-tree/
*/

bool isBalancedHeight(TreeNode *root, int &height) {
        if (!root) {
            height = 0;
            return true;
        } else if (!root->left && !root->right) {
            height = 1;
            return true;
        } else {
            int lh, rh;
            lh = rh = 0;
            if (isBalancedHeight(root->left, lh) && 
                isBalancedHeight(root->right, rh) &&
                std::abs(lh-rh) <= 1) {
                    height = std::max(lh,rh) + 1;
                    return true;
            } else 
                return false;
        }
    }
    
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return isBalancedHeight(root, height);
    }
