/*
Solution for : https://leetcode.com/problems/search-insert-position/
*/

/* Following solution is using Binary Search. However, implementing Binary search while
covering all cases is tricky. 
NOTE : lower count and upper count have been taken as int instead of size_t. size_t is 
unsigned long int and hence never gets negative so code might get into infinite loop.
TODO: I believe this can be improved to be succinct.
*/
int searchInsert(vector<int>& nums, int target) {
        size_t count = nums.size();
        if (!count)
            return 0;
        
        bool find = true;
        int ll =0, ul = count-1;
        
        while(ll < ul) {
            size_t mid = (ll + ul)/2;
            if (target == nums[mid])
                return mid;
            
            if (ll == ul) {
                return (target > nums[mid]) ? ll+1 : ll;
            }
            
            if (nums[mid] > target)
                ul = mid-1;
            else
                ll = mid+1;
        }
        return (target > nums[ll]) ? ll+1 : ll;;
    }
