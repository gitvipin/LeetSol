/*
Solution for : https://leetcode.com/problems/ugly-number-ii/
*/

UINT nthUglyNumber(UINT n) {
        if (n < 1)
            return 1;

        std::set<UINT> funs; //future ugly numbers
        
        UINT curr = 1;
        UINT count = 1;
        
        while (count < n) {
            UINT temp, temp1;
            
            temp = curr<<1;
            if (funs.find(temp) == funs.end())
                funs.insert(temp);
            
            temp1 = temp + curr;
            if (funs.find(temp1) == funs.end())
                funs.insert(temp1);
                
            temp += temp1;
            if (funs.find(temp) == funs.end())
                funs.insert(temp);
            
            std::set<UINT>::iterator iter = funs.begin();
            
            curr = *iter;
            count++;
            funs.erase(iter);
        }
        
        return curr;
    }
