/*
Solution for : https://leetcode.com/problems/nim-game/
*/


/*
HINT: try to deduce the solution along the lines of Fibonacci series. 
In a way can map to Dynamic programming as well. Solution for nth depends on
if you can confirmatively answer if n-1, n-2 or n-3 pushes the opponent to 
a definitive loss ( check-mate). 

So you can memoize the solution for lower values upto n and form the answer
for n on the basis of that. 

However, later on you will find that series is clearly giving the answer of
failure for n%4. 
*/

bool canWinNim(int n) {
        return n%4;
    }
