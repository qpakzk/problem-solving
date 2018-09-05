"""
Given n number of people in a room,
calculate the probability that any two people in that room have the same birthday
(assume 365 days every year = ignore leap year).
Answers should be two decimals unless whole (0 or 1) eg 0.05
"""
from  math import factorial
def calculate_probability(n):
    if n < 365:
        p = factorial(365) / (365**n * factorial(365 - n))
        result = round(1 - p, 2)
    else:
        result = 1
    return result





from unittest import TestCase

class TestBitsBattle(TestCase):
    def test_bits_battle(test):
        test.assertEqual(calculate_probability(5), 0.03)
        test.assertEqual(calculate_probability(15), 0.25)
        test.assertEqual(calculate_probability(1), 0)
        test.assertEqual(calculate_probability(365), 1)
        test.assertEqual(calculate_probability(366), 1)
