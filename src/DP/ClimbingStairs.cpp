/*
Solution for : https://leetcode.com/problems/climbing-stairs/
*/

int climbStairs(int n) {
        if (n <= 2)
            return n;
        int prev=1, curr = 2;
        
        for (int x = 3 ; x <= n; x++) {
            int xval = prev + curr;
            prev = curr;
            curr = xval;
        }
        
        return curr;
    }
