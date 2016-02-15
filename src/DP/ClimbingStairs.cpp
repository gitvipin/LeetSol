/*
Solution for : https://leetcode.com/problems/climbing-stairs/
*/

/*
Solution to this problem is an elegant application of Fibonacci Series. 

Basically at nth step you can come only two ways. First from (n-1)th step with 1 more step
or Second is from (n-2)nd step wiht 2 steps at a time. It means number of ways one can 
reach on nth step is sum of number of ways one can reach on (n-1) step and (n-2) step.

Following solution encodes this only. 
*/
int climbStairs(int n) {
        if (n <= 2)
            return n;
            
        // We need only (n-1) and (n-2) step solution so keep only two variables.
        int prev=1, curr = 2;
        
        for (int x = 3 ; x <= n; x++) {
            int xval = prev + curr;
            prev = curr;
            curr = xval;
        }
        
        return curr;
    }
