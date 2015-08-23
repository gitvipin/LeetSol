/*
Solution for : https://leetcode.com/problems/binary-tree-level-order-traversal/
*/

void computeR(TreeNode *root, int level, vector<vector<int>> &rslt) {
        if (!root)
            return;
        if (rslt.size() <= level) {
            vector<int> level;
            level.push_back(root->val);
            rslt.push_back(level);
        } else 
            rslt[level].push_back(root->val);
        
        computeR(root->left, level+1, rslt);
        computeR(root->right, level+1, rslt);
    }

    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> rslt;
        if (root)
            computeR(root, 0, rslt);
        return rslt;
    }
