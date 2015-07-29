// This program is the solution to following problem
// https://leetcode.com/problems/binary-tree-right-side-view/

void findR(TreeNode *root, int level, set<int> &mark, vector<int> & v)
{
    if(!root)
        return;

    if (mark.find(level) == mark.end()) {
        v.push_back(root->val);
        mark.insert(level);
    }
    findR(root->right, level+1, mark, v);
    findR(root->left, level+1, mark, v);
}




vector<int> rightSideView(TreeNode* root) {
    vector<int> v;
    set<int>	mark;
    findR(root, 0, mark, v);
    return v;
}


