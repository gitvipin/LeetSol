/*
Solution for : https://leetcode.com/problems/symmetric-tree/
*/

bool areChiral(TreeNode *t1, TreeNode *t2) {
        if (!t1 && !t2)
            return true;
        else if (t1 && t2) {
            return (t1->val == t2->val) &&
                    areChiral(t1->left, t2->right) &&
                    areChiral(t1->right, t2->left);
        } else
            return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return areChiral(root->left, root->right);
    }
