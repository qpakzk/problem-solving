"""
You're a programmer in a SEO company.
The SEO specialist of your company gets the list of all project keywords everyday,
then he looks for the longest keys to analyze them.

You will get the list with keywords and must write a simple function that returns the biggest search keywords and sorts them in lexicographical order.

For instance you might get:

'key1', 'key2', 'key3', 'key n', 'bigkey2', 'bigkey1'
And your function should return:

"'bigkey1', 'bigkey2'"
"""

def the_biggest_search_keys(*keys):
    biggest = list()
    if not keys:
        return "''"
    for key in keys:
        if not biggest:
            longest = len(key)
            biggest.append(key)
            continue
        if longest == len(key):
            biggest.append(key)
        elif longest < len(key):
            longest = len(key)
            del biggest[:]
            biggest.append(key)

    biggest.sort()
    b = list()
    for s in biggest:
        b.append("'" + s + "'")
    return ', '.join(b)

from unittest import TestCase

class TestTheBiggestSearchKeys(TestCase):
    def test_the_biggest_search_keys(test):
        test.assertEqual(the_biggest_search_keys("key1", "key22", "key333"), "'key333'")
        test.assertEqual(the_biggest_search_keys("coding", "sorting", "tryruby"), "'sorting', 'tryruby'")
        test.assertEqual(the_biggest_search_keys("small keyword", "how to coding?", "very nice kata", "a lot of keys", "I like Ruby!!!"),
                           "'I like Ruby!!!', 'how to coding?', 'very nice kata'")
        test.assertEqual(the_biggest_search_keys("pippi"), "'pippi'")
        test.assertEqual(the_biggest_search_keys(), "''")