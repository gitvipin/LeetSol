/*
Solution : https://leetcode.com/problems/binary-tree-preorder-traversal/
*/

vector<int> preorderTraversal(TreeNode* root) {
        vector <int> rslt;
        list<TreeNode*> queue;
        
        if (!root)
            return rslt;
        
        queue.push_back(root);
        
        while (!queue.empty()) {
            TreeNode *node = queue.front();
            queue.pop_front();
            
            rslt.push_back(node->val);
            
            if (node->right)
                queue.push_front(node->right);
            if (node->left)
                queue.push_front(node->left);
            
        }
        
        return rslt;
    }
