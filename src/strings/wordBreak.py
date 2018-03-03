#!/usr/bin/env python
'''
Solution for : https://leetcode.com/problems/word-break/description/

It is not mentioned in the problem description but you can use each
word of dictionary multiple times.
'''

class Solution1(object):
    '''
    This solution can be extended to when you have to save the solution as well.
    '''

    def wordBreak(self, istr, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        if not istr:
            return True
        if not wordDict:
            return False
        for x in wordDict:
            if istr.startswith(x):
                # wordDict.remove(x)    # can use the word multiple times.
                if self.wordBreak(istr[len(x):], wordDict):
                    # wordDict.append(x)
                    return True
                # wordDict.append(x)
        return False    # Nothing forms the string

class Solution(object):

    def wordBreak(self, istr, wordDict):
        chars = set()
        for word in wordDict:
            for char in word:
                chars.add(char)
        for char in istr:
            if char not in chars:
                return False
        return self.wordBreakR(istr, sorted(wordDict, key=len, reverse=True))

    def wordBreakR(self, istr, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        if not istr:
            return True
        if not wordDict:
            return False
        # print "checking ...", istr, " --> ", wordDict
        for x in wordDict:
            if istr.startswith(x) and self.wordBreakR(istr[len(x):], wordDict):
                    return True
        return False    # Nothing forms the string

if __name__ == '__main__':
   inputs = [
           ("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
           ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]),
        ("leetcode", ["leet", "code"]),
        ("elitecode", ["elit", "code", "elite"]),
        ("leetcode", ["lee", "code"]),
        ("elitecode", ["eli", "ecode", "elite"])
        ]

   for x, y in inputs:
       # import pdb ; pdb.set_trace()
       print "-" * 25
       print x , " and ", y
       print "Possible" if Solution().wordBreak(x, y) else "Not Possible"

