/*
Problem : https://leetcode.com/problems/contains-duplicate/
*/

bool containsDuplicate(vector<int>& nums) {
        size_t count = nums.size();
        if (!count)
            return false;
            
        std::unordered_map<int, int> tbl;
        //std::set<int> tbl;
        
        for (size_t i = 0; i < count; i++) {
            if (tbl.find(nums[i]) != tbl.end())
                return true;
            tbl[nums[i]] = 1;
            //tbl.insert(nums[i]);
        }
        return false;
    }
