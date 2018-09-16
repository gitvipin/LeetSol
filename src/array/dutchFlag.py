#!/usr/bin/env python
'''
Solution for : https://leetcode.com/problems/sort-colors/description/
'''

def dutchFlag(arr):
    '''
    Sorts three type of elements in an array in a single scan.

    It is simple. Keep 3 pointers in array. First one marks the end
    of first type of elements, third marks the beginning of third type
    of elements and second one just simply iterates over the array.

    Note that iterator is incremented in case match is found for first
    two cases while not incremented when match is for third type of
    element.
    '''
    zero, two = 0, len(arr) -1

    idx = 0
    while (idx < two):
        if arr[idx] == 0:
            arr[idx], arr[zero] = arr[zero], arr[idx]
            idx +=1
            zero +=1
        elif arr[idx] == 1:
            idx+=1
        elif arr[idx] == 2:
            arr[idx], arr[two] = arr[two], arr[idx]
            two -=1

class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        count = len(nums)
        if not count or count == 1:
            return nums

        # import pdb ; pdb.set_trace()
        zero, one, two = 0, 0, count - 1
        while one <= two:
            if nums[one] == 0:
                nums[zero], nums[one] = nums[one], nums[zero]
                zero += 1
                one += 1
            elif nums[one] == 1:
                one += 1
            elif nums[one] == 2:
                nums[two], nums[one] = nums[one], nums[two]
                two -= 1
            else:
                raise RuntimeError("Invalid Color")

        return nums

if __name__ == '__main__':
    Solution().sortColors([0,1,2,2,1,0])
    inputs = (
            [],
            [1], [2], [0],
            [0,1], [2,1], [0,2],
            [0,1,2,2,1,0])
    for x in inputs:
        print x, Solution().sortColors(x)



