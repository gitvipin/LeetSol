#!/bin/env/python

# Solution for : https://leetcode.com/problems/array-partition-i/description/
#
# To get the maximum sum, we need to include as many large numbers as possible
# Largest numbers at even positions would never win in min(ai,bi) selection so
# we have pick the numbers at odd position.
#
# It is an interesting problem to see an application of sorting.

class Solution(object):
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = sorted(nums) if nums is not None else nums
        return sum(nums[0::2])




