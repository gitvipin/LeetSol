/*
Solution for : https://leetcode.com/problems/ugly-number-ii/
*/

/*
Idea is basically to keep a pool of numbers obtained by multiplying the existing ugly numbers
by 2 , 3 and 5. The smallest number is picked up from the pool and eliminated from pool there-
after. The nth number obtained in the order is the answer.
*/
UINT nthUglyNumber(UINT n) {
        if (n < 1)
            return 1;

        std::set<UINT> funs; //future ugly numbers
        
        UINT curr = 1;  // current ugly number
        UINT count = 1; // count ugly number seen so far
        
        while (count < n) {
            UINT temp, temp1;
            
            temp = curr<<1;  // get fast 2*curr
            if (funs.find(temp) == funs.end())
                funs.insert(temp);
            
            temp1 = temp + curr; // get fast 3*curr
            if (funs.find(temp1) == funs.end())
                funs.insert(temp1);
                
            temp += temp1;      // get fast 5*curr
            if (funs.find(temp) == funs.end())
                funs.insert(temp);
            
            // std::set is implmented as Balanced Binary Search Tree
            // .begin() will return the first element in inorder traversal
            // which will be smallest. 
            // TODO : Try minheap instead. It will be implementation independent.
            std::set<UINT>::iterator iter = funs.begin();
            
            curr = *iter;
            count++;
            funs.erase(iter);
        }
        
        return curr;
    }
