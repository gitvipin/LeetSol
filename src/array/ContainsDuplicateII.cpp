/*
Problem: https://leetcode.com/problems/contains-duplicate/
*/

bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int count = nums.size();
        
        if (!count)
            return false;
            
        std::set<int> window;
        
        //gather window
        for (int i = 0; i < count; i++) {
            if (i > k)
                window.erase(nums[i-k-1]);
            if (window.find(nums[i]) != window.end())
                return true;
            window.insert(nums[i]);
        }
        return false;
    }
