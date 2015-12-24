

/*
Solution for : https://leetcode.com/problems/move-zeroes/
*/

/*
NOTE
1. It is O(n)
2. It will not make any moves if there is no zero in array. (minimize moves)
*/
void moveZeroes(vector<int>& nums) {
        int i, j, sz = nums.size();
        i = j = 0;
        for (; i < sz; i++) {
            if (nums[i]) 
                (i != j) ? nums[j++] = nums[i] : j++;
        }
        while (j < i)
            nums[j++] =0;
    }
