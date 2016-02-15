/*
Solution for : https://leetcode.com/problems/house-robber/
*/

/*
Dynamic Programming offers a neat and clean solution for this problem. 
At nth house, robber can check what gives more yield : Robbing this and previous alternate
house or yield on immediate previous house.
*/
 int rob(vector<int>& nums) {
        
        size_t count = nums.size();
        
        if ( count == 0)
            return 0;
        else if (count == 1)
            return nums[0];
            
        int prev = nums[0];
        int curr = std::max(nums[0], nums[1]);
        
        if (count == 2)
            return curr;
        
        for (size_t x = 2; x < count; x++) {
            int max = std::max(prev + nums[x], curr); // it calculates the max yield until xth house.
            prev = std::max(prev, curr); // Also update the yield till previous house.
            curr = max;
        }
        return std::max(prev, curr);
    }
