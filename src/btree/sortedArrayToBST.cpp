/*
Solution for : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
*/

/*
This solution to this problem is based on Divide & Conquer approach. Implementation is done
using recursion for the succinctness of the code. 

Idea is for any given array of sorted numbers, a height balanced tree can be constructed if 
half the elements are on LHS and half on RHS. So pick the middle element, make it root and 
then recursively call for constructing the balanced tree for left half elements of the array and 
right half elements of the array. Append these trees on left and right node of root.
*/

TreeNode* sortedArrayToBST(vector<int>& nums) {
        size_t count = nums.size();
        if (!count)
            return NULL;
        else
            return generateR(nums, 0, count-1);
}

TreeNode *generateR(vector<int>& nums, size_t beg, size_t end) {
        size_t count = nums.size();
        TreeNode *root = NULL;
        if (beg > end || beg >= count)
            return root;
        
        // use of std::ceil ensures that LHS has of root has more elements 
        // than right.
        size_t mid = std::ceil((beg + end)/2.0);
        
        root = new TreeNode(nums[mid]);
        if (beg != end) {
            root->left = generateR(nums,beg, mid-1);
            root->right = generateR(nums,mid+1, end);
        }
        return root;
    }
    
//FOLLOW UP : Try without recursion. HINT: std::queue<std::pair<int_beg, int_end> >
