/*
Solution for : https://leetcode.com/problems/binary-tree-paths/
*/

char num[10];
    
    char *itoa(int x) {
        sprintf(num,"%d", x);
        return num;
    }
    
    void getAllPaths(TreeNode *root, string curr, vector<string> & rslt) {
        if (!root->left && !root->right) {
            rslt.push_back(curr);
            return;
        }
        
        if (root->left) {
            string tmp = curr + "->" + string(itoa(root->left->val));
            getAllPaths(root->left, tmp, rslt);
        }
        
        if (root->right) {
            string tmp = curr + "->" + string(itoa(root->right->val));
            getAllPaths(root->right, tmp, rslt);
        }
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>  rslt;
        
        if (root) {
            string curr = string(itoa(root->val));
            getAllPaths(root, curr, rslt);
        }
        
        return rslt;
    }
