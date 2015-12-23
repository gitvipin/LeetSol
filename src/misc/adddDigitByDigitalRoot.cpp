/*
Solution for : https://leetcode.com/problems/add-digits/
*/


/*
HINT : 
Solving through the conventional methods is easy such as 
1) Recursion 
2) While loop on sum until sum  < 10
3) Use string to move n into string first and then keep adding sum at end and process string until NULL character.

HINT : Sum of digits of 13 is always (1 + sum (12)) modulo 10
Check Digital root on wiki
*/
int addDigits(int num) {
        return num - 9 * (std::ceil((num-1)/9));
    }
