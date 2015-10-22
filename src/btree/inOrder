/*
Solution for : https://leetcode.com/problems/binary-tree-inorder-traversal/
*/

 void inorderR(TreeNode *root, vector<int> & soln) {
        if (!root)
            return;
        inorderR(root->left, soln);
        soln.push_back(root->val);
        inorderR(root->right, soln);
    }
    #if 0
    // Recursive Solution
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> soln;
        inorderR(root, soln);
        return soln;
        
    }
    #else
    // Non-recursive solution 
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> soln;
        stack<TreeNode*>  aux;
        std::set<TreeNode*> visited;
        
        while(root) {
            if (root->left && 
                visited.find(root->left) == visited.end()) {
                aux.push(root);
                root = root->left;
                continue;
            }
            soln.push_back(root->val);
            visited.insert(root);
            if (root->right &&
                visited.find(root->right) == visited.end()) {
                root = root->right;
            } else if (!aux.empty()){
                root = aux.top();
                aux.pop();
            } else {
                root = NULL;
            }
        }
        
        return soln;
        
    }
    #endif
