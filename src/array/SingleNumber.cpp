/*
Solution for : https://leetcode.com/problems/single-number/
*/

int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto i = nums.begin(); i != nums.end(); i++) {
            ans = ans ^ (*i);
        }
        return ans;
    }
