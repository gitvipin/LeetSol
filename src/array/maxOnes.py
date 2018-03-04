#!/usr/bin/env python

'''
Solution for : https://leetcode.com/problems/max-consecutive-ones/description/
'''

class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return None
        x = nums
        _sum, _max = x[0], x[0]
        for i in range(1, len(x)):
            if not x[i]:
                _max = _sum if _sum > _max else _max
                _sum = 0
            else:
                _sum += x[i]
        _max = _sum if _sum > _max else _max

        return _max


if __name__ == '__main__':
    _input = [0,1]
    print Solution().findMaxConsecutiveOnes(_input)

