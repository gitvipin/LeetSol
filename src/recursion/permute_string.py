#!/usr/bin/env python
'''
Solution for : https://leetcode.com/problems/permutations/description/
'''
class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ans = []
        self.permuteR(nums,0, len(nums)-1, ans)
        return ans


    def permuteR(self, nums, l, r, ans):
        if l == r:
            ans.append([i for i in nums])

        for i in range(l,r+1):
            nums[l] , nums[i] = nums[i], nums[l]
            self.permuteR(nums, l + 1, r, ans)
            nums[l] , nums[i] = nums[i], nums[l]


if __name__ == '__main__':
    print "Permutation of 1234 : ", Solution().permute([i for i in "1234"])
    print "Permutation of goat : ", Solution().permute([i for i in "goat"])

