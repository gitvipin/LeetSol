#!/usr/bin/env python
'''
Input --> a1a2a3a4
Output --> aaaaaaaaaaa1234
'''


import sys

def isNum(x):
    try:
        _ = int(x)
        return True
    except Exception:
        return False

def isAlpha(x):
    try:
        return x.isalpha()
    except Exception:
        return False

def isValid(data):
    '''
    Data is valid if it has even number of changes from
    alphabet to number. Then only we
    '''
    if not data:
        return False
    count = 0
    for x in range(0,len(data)-1):
        if (isAlpha(data[x]) and isNum(data[x+1])) or (isNum(data[x]) and isAlpha(data[x+1])):
            count += 1
    return count % 2



def fix(data, start, end):
    if start >= end:
        return
    idx = start
    str1, num1= '', ''
    str2, num2= '', ''

    while idx <= end and isAlpha(data[idx]):
        str1 += data[idx]
        idx += 1
    while idx <= end and isNum(data[idx]):
        num1 += data[idx]
        idx += 1
    while idx <= end and isAlpha(data[idx]):
        str2 += data[idx]
        idx += 1
    while idx <= end and isNum(data[idx]):
        num2 += data[idx]
        idx += 1

    # TODO : can optimize. We don't need to extract
    # first string and last number. We can do that in place but python
    # anyway doesn't change it in-place and we have to use following
    # expression.
    data = data[0:start] + str1 + str2 + num1 + num2 + data[end+1:]
    return data


def arrange(data):
    if not isValid(data):
        print "Invalid input (unmatched str/num) - ", data
        return data

    start, end = 0, len(data)
    found = True
    while found:
        start, idx, count = 0, 0, 0
        found = False

        while idx < end:
            if isNum(data[idx]) and (idx + 1 == end or isAlpha(data[idx+1])):
                count +=1

            if count == 2:
                found = True
                data = fix(data, start, idx)
                count = 0
                start = idx + 1
            idx += 1
            # end of first loop
        # end of second loop

    return data



if __name__ == '__main__':
    # data = 'aaa123bbb12ccc1dddd123'   # sys.argv[1]
    for data  in ['a1a', 'a1b2c3d4', 'a1a2', 'aaa123bbb12ccc1dddd123', 'a1a2a3', 'a1a2a']:
        print "Before fix:" , data
        data = arrange(data) # fix(data, 6,14)
        print "After fix:" , data


