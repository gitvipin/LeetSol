/*
Solution for : https://leetcode.com/problems/single-number-iii/
*/

/*
You can solve this problem in multiple ways. 

Solution 1 : Using hash_Map<num,count> 
a. Scan the array and for every element 'e' in array insert in hash map and initialize count as 1
   if it is not already present. Increment count otherwise. 
b. Scan the hash map and return the numbers which have count as 1 only. 

This solution has complexity O(n) but space complexity is also O(n).

Solution 2 :
1) Sort the array 
2) Scan the sorted array and return the elements which are present only once.
This solution has complexity of O(nlogn) and space complexity as constant. 


Solution 3 :
Let the unique numbers be A and B.
1) Scan the array and compute Xor of all elements 
2) Xor of all products is now A^B. Also the bits which are 1 in Xor are 1 only either in A or B.
3) Based on above find out a bit position which is '1' in A^B. It distinguishes A from B.
4) Scan all the array again and computer Xor of all numbers which have this bit 1 ( or not ).
5) New final Xor is either 'A' or 'B'
6) Xor this Xor with previous Xor and output is B

*/

vector<int> singleNumber(vector<int>& nums) {
        vector<int> soln;
        
        size_t count = nums.size();
        
        // handle / process special cases.
        if (!count)
            return soln;
        else if (count <= 2) {
            soln.push_back(nums[0]);
            soln.push_back(nums[1]);
            return soln;
        }
        
        // Let A and B be the unique numbers. 
        // compute A^B
        int xxor = 0;
        for (size_t x = 0; x < count ; x++)
            xxor ^= nums[x];
        
        // Find LSB which is '1' in A^B
        int lsb = xxor & ~(xxor-1);
        
        soln.push_back(0);
        // Scan and Xor which have lsb as 1.
        for (size_t x = 0; x < count ; x++)
            if(lsb & nums[x])
                soln[0] ^= nums[x];
        
        // Compute the second number.
        soln.push_back(xxor ^ soln[0]);
        return soln;
    }
