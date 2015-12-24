

/*
Solution for : https://leetcode.com/problems/majority-element/
*/

/*
NOTE 
Time : O(n)
Space : O(n)

Other approach 
1) Sort in nlogn and single scan can tell majority element. In place if can modify array

*/
 int majorityElement(vector<int>& nums) {
        size_t i, sz = nums.size();
        std::unordered_map<int,int> tbl;
        
        for (i = 0; i < sz ; i++) {
            if (++tbl[nums[i]] > std::ceil(sz/2))
                return nums[i];
        }
    }
