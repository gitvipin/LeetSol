
/*
Solution for : https://leetcode.com/problems/kth-smallest-element-in-a-bst/
*/

int kthSmallestR(TreeNode* root, int k, int &rank, int &kth) {
        //  exit condition and primary checks
        if (rank >= k || !root)
            return kth;
        
        if (root->left)
            kthSmallestR(root->left, k, rank, kth);
            
        ++rank;
        if (rank == k) {
            kth = root->val;
            return kth;
        }

        if (root->right)
            kthSmallestR(root->right, k, rank, kth);
        
        return kth;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int rank = 0;
        int kth = 0;
        return kthSmallestR(root, k, rank, kth);
    }
