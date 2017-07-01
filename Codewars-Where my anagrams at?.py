"""
What is an anagram? Well, two words are anagrams of each other if they both contain the same letters. For example:

'abba' & 'baab' == true

'abba' & 'bbaa' == true

'abba' & 'abbba' == false
Write a function that will find all the anagrams of a word from a list.
You will be given two inputs a word and an array with words.
You should return an array of all the anagrams or an empty array if there are none. For example:

anagrams('abba', ['aabb', 'abcd', 'bbaa', 'dada']) => ['aabb', 'bbaa']

anagrams('racer', ['crazer', 'carer', 'racar', 'caers', 'racer']) => ['carer', 'racer']

anagrams('laser', ['lazing', 'lazy',  'lacer']) => []
"""

def anagrams(word, words):
    lst_word = list(word)
    lst_word = list(set(lst_word))
    lst_word.sort()

    result = []
    for x in words:
        if len(word) == len(x):
            lst_x = list(x)
            lst_x = list(set(lst_x))
            lst_x.sort()
        else:
            continue

        isAnarams = True
        if len(lst_word) == len(lst_x):
            for i in range(len(lst_x)):
                if lst_x[i] != lst_word[i]:
                    isAnarams = False
                    break
            if isAnarams == True:
                result.append(x)

    return result

from unittest import TestCase

class TestAnagrams(TestCase):
    def test_anagrams(test):
        test.assertEqual(anagrams('abba', ['aabb', 'abcd', 'bbaa', 'dada']), ['aabb', 'bbaa'])
        test.assertEqual(anagrams('racer', ['crazer', 'carer', 'racar', 'caers', 'racer']), ['carer', 'racer'])