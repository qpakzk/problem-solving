"""
Complete the solution so that it reverses the string value passed into it.

solution('world') # returns 'dlrow'
"""

def solution(str):
    return str[::-1]

from unittest import TestCase

class TestSolution(TestCase):
    def test_solution(self):
        self.assertEqual(solution('world'), 'dlrow')
        self.assertEqual(solution('hello'), 'olleh')
        self.assertEqual(solution(''), '')
        self.assertEqual(solution('h'), 'h')