/*
------------------------------------------------------------------------
https://leetcode.com/problems/valid-anagram/
------------------------------------------------------------------------
*/

/*
There are multile ways to solve this problem. 

Soln (1) : For every character in first string, check if it is also present in second string as well. Also ensure that character 
appears same number of time in second string. If checks match return true . 
Time : O(n*2) , 
Space : O(1) [ PS : To handle muliple occurence of characters, you can swap the matched character with the last one and move the counter
of length of string to be matched a bit ahead. Recale random number generator trick]


Soln (2) : Sort both the strings and compare.
Time : O(nlogn) Space : O(1) but with a serious side effect on string which gets mutated.

Soln (3) : Scan the first string and hash all the characters with incrmeenting count. Scan second string and decrement count of every character
every time. Scan the hash table and if any of the character has count > 1 or < 1 , return false else return true.

Soln (4 **) : If it is guaranted that no character repeats itself in any of the strings, "unsigned long int" itself can be taken as 
the hashmap. unsigned long int is 32 bit wide. Mark corresponding bit for every character in string as 1 for both the strings. if the
hash-map for two strings are equal, return true else return false.

*/

bool isAnagram(string s, string t) {
        
    if (s.empty() && t.empty())
        return true;

    /*  Note that length in std::string is precomputed so it doesn't put performance penalty and it is a good 
        check to gain performance. */
    if (s.length() != t.length())
        return false;
    
    std::unordered_map<char, int> smap;
    
    for (auto i = s.begin(); i != s.end(); i++) 
        smap[*i]++;

    for (auto i = t.begin(); i != t.end(); i++) 
        smap[*i]--;

    for (auto iter = smap.begin(); iter != smap.end(); iter++)
        if (iter->second)
            return false;
            
    return true;
    }

