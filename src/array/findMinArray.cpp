/*
Solution for : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
*/

int findMinR(vector<int>& nums, size_t beg, size_t end) {
        if (beg == end)
            return nums[beg];
        else if (end == beg+1)
            return std::min(nums[beg], nums[end]);
        else {
            size_t mid = (beg + end)/2;
            if (nums[end] > nums[mid])
                return findMinR(nums, beg, mid);
            else
                return findMinR(nums, mid, end);
        }
        
    }
    
    int findMin(vector<int>& nums) {
        size_t count = nums.size();
        return (count) ? findMinR(nums, 0, count-1) : 0;
    }
