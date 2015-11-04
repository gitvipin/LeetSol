/*
Solution for : https://leetcode.com/problems/unique-binary-search-trees-ii/

To understand this solution, it is helpful to understand the solution for sister problem to count number of unique binary search trees for 'N'
Refer to the solution of that problem from Index.
*/

 vector<TreeNode*> generateR(int start, int end) 
    {
        vector<TreeNode*> soln;
        if (start > end) {
            soln.push_back(NULL);
            return soln;
        }
        
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftS = generateR(start, i-1);
            vector<TreeNode*> rightS = generateR(i+1, end);
            for (auto &j :leftS) {
                for (auto &k : rightS) {
                    TreeNode *node = new TreeNode(i);
                    node->left = j;
                    node->right = k;
                    soln.push_back(node);
                }
            }
        }
        return soln;
    }
    vector<TreeNode*> generateTrees(int n) {
        return generateR(1,n);
    }
