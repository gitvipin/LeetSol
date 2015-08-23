/*
Solution for problem :https://leetcode.com/problems/path-sum-ii/
*/

vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector< vector<int> > rslt;
        vector <int> path;
        
        if (!root)
            return rslt;
        else 
            ComputeR(root, sum, path, rslt);
        return rslt;
    }
    
    
    void ComputeR(TreeNode *root, int sum, vector<int> &path, vector<vector<int>> &rslt) {
        if (!root)
            return;
        else if ( !root->left && !root->right) {
            if (root->val == sum) { // accept the path so far as solution
                path.push_back(root->val);
                rslt.push_back(path);
                path.pop_back();
                return;
            }
        } else {
            path.push_back(root->val);
            ComputeR(root->left, sum - root->val, path, rslt);
            ComputeR(root->right, sum - root->val, path, rslt);
            path.pop_back();
        }
    }
