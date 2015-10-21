/*
Solution for : https://leetcode.com/problems/product-of-array-except-self/
*/

vector<int> productExceptSelf(vector<int>& nums) {
        size_t count = nums.size();
        vector<int> soln(nums);
        
        if (!count)
            return soln;
        
        int prod = 1;
        for (int i = 0; i < count ; i++) {
            soln[i] = prod;
            prod *= nums[i];
        }
        prod = 1;
        for (int i = count-1; i >= 0 ; i--) {
            soln[i] *= prod;
            prod *= nums[i];
        }
        
        return soln;
    }
