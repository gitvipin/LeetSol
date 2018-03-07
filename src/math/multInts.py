#!/usr/bin/env python
'''
Multiply two integers without using "*" operator.
'''

def mult(a, b):
    """
    Multiplies two integers
    """
    try:
        a = int(a)
        b = int(b)

        # TODO
        # 1) -ve numbers
        # 2) If one number is 1 only or zero

        if a == 0 or b == 0:
            return 0

        polarity = (a < 0) ^ (b <0)


        if a < 0:
            a = a - a -a

        if b < 0:
            b = b - b -b

        if a == 1:
            return b if not polarity else b - b - b
        elif b == 1:
            return a if not polarity else a - a - a

        ans = 0
        for i in range(b):
            ans += a

        return ans if not polarity else ans - ans - ans


    except Exception as err:
        raise

print mult(0,2)
print mult (-1,-2)
print mult(-1,2)
print mult(1, -2)
print mult(2,3)
print mult(10,15)
print mult(10.2, 32.4)

