"""
Impliment the reverse function,
which takes in input n and reverses it.
For instance, reverse(123) should return 321.
You should do this without converting the inputted number into a string.
"""

def reverse(n):
    s = str(n)
    r_s = s[::-1]
    r_n = int(r_s)
    return r_n

from unittest import TestCase

class TestReverse(TestCase):
    def test_reverse(test):
        test.assertEqual(reverse(1234), 4321)
        test.assertEqual(reverse(10987), 78901)
        test.assertEqual(reverse(1020), 201)