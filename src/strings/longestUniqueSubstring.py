#!/usr/bin/env python
'''
Solution for : https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
'''

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s or len(s) <= 1:
            return len(s)

        i, count = 0, len(s)
        mapping, maxlen, ans, start = {}, 0, 0, 0

        while i < count:
            ch = s[i]   # current char
            if ch not in mapping.keys(): # not seen yet
                mapping[ch] = i
                maxlen += 1
                i += 1
            else:   # seen previously
                import pdb ; pdb.set_trace()
                if maxlen > ans:    # update answer
                    ans = maxlen

                pindex = mapping[ch] # previous index
                # remove previous entries
                for j in range(start, pindex+1):
                    mapping.pop(s[j])
                    maxlen -=1
                start = pindex + 1

                mapping[ch] = i
                maxlen += 1
                i += 1

        if maxlen > ans:
            ans = maxlen
        return ans

if __name__ == '__main__':
    inputs = ["abcabcbb"]
    for i in inputs:
        try:
            x = Solution().lengthOfLongestSubstring(i)
        except Exception as err:
            _ = err
        print "Length of unique substr in " , i, " is " , x


