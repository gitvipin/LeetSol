/*
Problem : https://leetcode.com/problems/happy-number/
*/

int getSum(int n) {
        int sum = 0;
        while (n) {
            int digit = n %10;
            sum += digit * digit;
            n = n/10;
        }
        return sum;
    }

    bool isHappy(int n) {
        if ( n == 1)
            return true;
        else if ( n <= 0)
            return false;
            
        std::set<int>  tbl;
        
        tbl.insert(n);
        int digitSum = n;
        while(1) {
            digitSum = getSum(digitSum);
            
            if (digitSum == 1)
                return true;
            else if (tbl.find(digitSum) != tbl.end())
                return false;
            tbl.insert(digitSum);
        }
        return false;
    }
