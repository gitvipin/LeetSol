/*
------------------------------------------------------ 
Problem : https://leetcode.com/submissions/detail/34578499/
------------------------------------------------------ 
*/

/*
QTA (Questions to ask): 
1) Should negative numbers be considered without negative sign or not. 
*/

/*
APCH (Approach):
There are multiple ways to solve this. 

Soln (1) : Convert the number into string and then perform check on String. But this is inefficient.
Soln (2) : Form another number with bit siginificance reversed and check if this number is same as original. If yes return true.
Soln (3) : Actually, you don't need to form the whole number from remainders and somewhere in middle itself two numbers will become equal. 

Soln(2) and Soln(3) both will competete for performance as in one we are processing whole number and in other we are performing division
and equality check again and again. Below is the implementation of Soln (2). 
*/
bool isPalindrome(int x) {
        if (x <0)
           return false;
        int y = 0;
        int z = x;
        while (z) {
            y = y * 10 + (z % 10);
            z = z/10;
        }
        return (y == x);
    }
