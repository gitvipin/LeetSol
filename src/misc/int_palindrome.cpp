/*
------------------------------------------------------ 
Problem : https://leetcode.com/submissions/detail/34578499/
------------------------------------------------------ 
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
