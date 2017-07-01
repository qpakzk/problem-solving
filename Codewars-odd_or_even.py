"""
Create a function that takes an integer as an argument and returns "Even" for even numbers or "Odd" for odd numbers.
"""
def OddOrEven(number):
    if number % 2 == 0:
        return 'Even'
    else:
        return 'Odd'

from unittest import TestCase

class TestOddOrEven(TestCase):
    def test_odd_or_even(self):
        self.assertEqual(OddOrEven(2), 'Even')
        self.assertEqual(OddOrEven(1), 'Odd')
