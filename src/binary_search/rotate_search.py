#!/bin/usr/env python
'''
Solution for : https://leetcode.com/problems/search-in-rotated-sorted-array/description/
'''

import random

def find_idx(data, start, end, item):
    """
    Assuming the data is a sorted but rotated array,
    this function returns the point where the item occurs between
    start and end
    """
    if not data or start > end:
        return None

    mid = (start + end ) / 2
    # print "\n searching in " , data[start:end], " ==> ", mid
    if data[mid] == item:
        return mid
    elif start == end:
        return None
    elif start +1 == end:
        if data[start] == item:
            return start
        elif data[end] == item:
            return end

    sorted_left = data[start] < data[mid]
    sorted_right = data[mid] < data[end]

    if sorted_left:
        if item >= data[start] and item < data[mid]:
            return find_idx(data, start, mid -1, item)
        else:
            return find_idx(data, mid + 1, end, item)
    else:
        if item > data[mid] and item <= data[end]:
            return find_idx(data, mid+1, end, item)
        else:
            return find_idx(data, start, mid -1 , item)



if __name__ == '__main__':
    data = range(8,12) + range(0,8)


    sample = range(0,14)
    random.shuffle(sample)

    print data
    #import pdb ; pdb.set_trace()
    #ans = find_idx(data, 0, len(data)-1, 0)
    for item in sample:
        ans = find_idx(data, 0, len(data)-1, item)
        print item, " occurs at ", ans






