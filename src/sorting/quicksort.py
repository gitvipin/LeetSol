#!/usr/bin/env python

class Solution(object):


    def qsort_R(self, arr, left, right):
        if left >= right:
            return
        mid = (left + right) / 2

        arr[left], arr[mid] = arr[mid], arr[left]
        last = left

        idx = left +1
        while idx <=right:
            if arr[idx] <= arr[left]:
                last += 1
                arr[last] , arr[idx] = arr[idx] , arr[last]
            idx +=1

        arr[left], arr[last] = arr[last], arr[left]
        self.qsort_R(arr, left, last -1)
        self.qsort_R(arr, last + 1, right)

    def sort(self, nums):
        nums = self.qsort_R(nums, 0, len(nums)-1)


if __name__ == '__main__':

    inputs = [
            [1,27,3,8,4,7,2,1],
            [1,27,38,47,21],
            [1,2],
            [],
            [1]
            ]

    for i in inputs:
        print "Before Sorting : " , i
        Solution().sort(i)
        print "After Sorting :", i
