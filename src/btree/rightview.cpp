/*
Solution for : https://leetcode.com/problems/binary-tree-right-side-view/
*/

/*
This problem can be solved in multiple ways. 

(1) Do a simple Level order traversal (using BFS),  Store the last element of every level. 
Time Complexity : O(n) , 
Space Complexity : O (n), You need to store all the nodes in between as you do not know 
which node will lead to right most node of next level. 

(2) Do a modified, Pre-Order traversal. In pre-order, traversal is Root->Left->right
We modify it to be Root->Right->Left and also keep a check of every level for which node (right most)
has already been added. Following solution is implmentation of this approach.
Time Complexity : O(n)
Space Complexity : O(logn), At most you are traversing down one path on Binary tree. So max, logn nodes in stack
*/

void findR(TreeNode *root, int level, set<int> &mark, vector<int> & v)
{
    if(!root)
        return;

    if (mark.find(level) == mark.end()) {
        v.push_back(root->val);
        mark.insert(level);
    }
    
    // We need to descend through both the branches as we don't know which path will lead to next
    // right most node.
    findR(root->right, level+1, mark, v);
    findR(root->left, level+1, mark, v);
}




vector<int> rightSideView(TreeNode* root) {
    vector<int> v;
    set<int>	mark;
    findR(root, 0, mark, v);
    return v;
}


