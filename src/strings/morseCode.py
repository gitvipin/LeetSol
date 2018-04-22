#!/usr/bin/env python

'''
Solution for : https://leetcode.com/problems/unique-morse-code-words/
'''

class Solution(object):
    def uniqueMorseRepresentations(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        if not words:
            return 0

        _dict = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]

        sols = set()
        for w in words:
            if not w:
                continue
            t = ''
            for char in w:
                try:
                    t += _dict[ord(char) - 97]
                except Exception as err:
                    pass
            sols.add(t)

        return len(sols)

if __name__ == '__main__':
        _inputs = [
                 (["gin", "zen", "gig", "msg"], 2)
        ]

        for x in _inputs:
            assert(Solution().uniqueMorseRepresentations(x[0]) == x[1])



