/*
Solution for : https://leetcode.com/problems/rotate-array/
*/

void rotate(vector<int>& nums, int k) {
        if (k <= 0 || nums.size() <= 1)
            return;
        //if (k > nums.size())
            k %= nums.size();
        std::reverse(nums.begin(), nums.end());
        auto itr = nums.begin();
        std::reverse(itr, itr+k);
        std::reverse(itr+k, nums.end());
    }
