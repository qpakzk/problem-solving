"""
late_clock function receive an array with 4 digits and should return the latest time that can be built with those digits.
The time should be in HH:MM format.

Examples:

[1, 9, 8, 3] => 19:38
[9, 1, 2, 5] => 21:59
You can suppose the input is correct and you can build from it a correct 24-hour time.
"""

def late_clock(digits):
    digits.sort()
    time = str()

    for x in digits:
        if x > 2:
            break
        h1 = x
    digits.remove(h1)

    if h1 == 2:
        for x in digits:
            if x > 3:
                break
            h2 = x
    else:
        h2 = digits[-1]

    digits.remove(h2)

    hasNumber = False

    for x in digits:
        if x <= 5:
            hasNumber = True
            break
    if hasNumber == True:
        for x in digits:
            if x > 5:
                break
            m1 = x
        digits.remove(m1)

        m2 = digits.pop()
    else:
        m1 = h1
        h1 = h2
        h2 = digits.pop(-1)
        m2 = digits.pop()

    time = str(h1) + str(h2) + ':' + str(m1) + str(m2)
    return time

from unittest import TestCase

class TestTheLatestClock(TestCase):
    def test_late_clock(test):
        test.assertEqual(late_clock([9, 1, 2, 5]), '21:59')
        test.assertEqual(late_clock([0, 2, 2, 2]), '22:20')
        test.assertEqual(late_clock([9, 0, 1, 1]), '19:10')
        test.assertEqual(late_clock([2, 3, 2, 4]), '23:42')
        test.assertEqual(late_clock([1, 2, 8, 9]), '19:28')
