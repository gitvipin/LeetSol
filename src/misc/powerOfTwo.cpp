/*
-----------------------------------------------------------------------------------
https://leetcode.com/problems/power-of-two/
-----------------------------------------------------------------------------------
*/

/*
A number is power of two if it has only 1 bit as '1' in its 2's complement representation.

For a 2's complement number, (n-1) converts all the least significant zeroes to 1 and 
converts the first least significant 1 to zero. So if (n) & (n-1) is zero, it means
there was only 1 bit as one in the whole integer. 

NOTE : same concept is used for counting in number of 1 bits in a number which is useful
, for e.g., in knowing different entries in a hash table is 'int' is used as bit vector.
*/
bool isPowerOfTwo(long int n) {
    return n ? !(n & (n-1)) : false;
}


