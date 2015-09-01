/*
Problem : https://leetcode.com/problems/excel-sheet-column-number/
*/

int titleToNumber(string s) {
        if (s.empty())
            return 0;
        
        const char *str = s.c_str();
        int retVal = 0;
        
        while (char ch = *str++) {
            int val = (ch >= 'A' && ch <= 'Z' ) ? ch - 'A' + 1:
                      (ch >= 'a' && ch <= 'z' ) ? ch - 'a' + 1: 0;
            if (val)
                retVal = retVal * 26 + val;
        }
        return retVal;
    }
