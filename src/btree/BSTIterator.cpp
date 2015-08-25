
/*
Solution for : https://leetcode.com/problems/binary-search-tree-iterator/
TODO : Using std::list was a temporary solution as proof of concept. Replace it with Stack and see if it makes it in top 5 %ile
in terms of runtime. Currently it is too bad. 
*/

class BSTIterator {
public:
    list<TreeNode*> pRoots;
    
    void fillStack(TreeNode *root) {
        if (!root)
            return;
        while (root) {
            pRoots.push_back(root);
            root = root->left;
        }
    }
    
    /* Pop until the child node is left of its parent.*/
    void popRight() {
        if (!pRoots.size())
            return;
        TreeNode *child, *parent;
        parent = pRoots.back();
        do {
            child = parent;
            pRoots.pop_back();
            parent = pRoots.size() ? pRoots.back() : NULL;
        } while(child && parent && child == parent->right);
    }
    
    BSTIterator(TreeNode *root) {
        pRoots.clear();
        fillStack(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return pRoots.size();
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *node = pRoots.back();
        // Update successor
        if (node->right) {
            fillStack(node->right);
        } else {
            popRight();
        }
        return node->val;
    }
};
