/*
Problem : https://leetcode.com/problems/ugly-number/
*/

bool isUgly(int num) {
        if (num <= 0)
            return false;

        while (num) {
            // Process 
            if (!(num % 2)) {
                num = num/2;
            } else if (!(num%3)) {
                num = num/3;
            } else if (!(num%5)) {
                num = num/5;
            } else if (num == 1) {
                return true;
            } else {
                return false;
            }
        }
    }
