/*
Solution for : https://leetcode.com/problems/missing-number/
*/

int missingNumber(vector<int>& nums) {
        size_t count = nums.size();
        
        if (!count)
            return 0;
            
        int sum = 0;
        for ( size_t x = 0; x <count; x++) {
            sum += nums[x];
        }
        return (count *(count+1)/2) - sum;
    }
