/*
Solution for problem : https://leetcode.com/problems/path-sum/
*/

/*
This problem can be solved in multiple ways. 

1) Collect all paths from root to leaves and return if any one of them matches the Sum. 
   Paths can be stored in vector<TreeNode*>. 
   Time Complexity : O(n) , Space complexity : nlogn . There are logn paths and n nodes. in worst case, a node is in every path. 

2) Traverse every path and while traversing the path, keep checking the sum. The first path you find with sum matching, return true. 
 This obviously is bette because you don't traverse whole tree and rather return true on first answer
   Time Complexity : O(n) , Space complexity : O(logn)

QTA :  
Are noeds all positive integer ?  It can lead to perform optimization in runtime such that if running sum has exceeded 
then no need to continue
Is tree an augmented tree ? i.e. with every node having parent node pointer ? If so, it can eliminate the need of extra space ?
In the later case, solution without recursion should be preferred.
*/



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


