"""
Move the first letter of each word to the end of it, then add 'ay' to the end of the word.

pig_it('Pig latin is cool') # igPay atinlay siay oolcay

"""

def pig_it(text):
    words = []
    for word in text.split(" "):
        words.append(word)
    # words : ['Pig', 'lation', 'is', 'cool']

    words_new =[]
    for word in words:
        alphabets = list(word)
        # words[0] : 'pig' -> alphabets : ['P', 'i', 'g']

        first = alphabets.pop(0)
        alphabets.append(first)

        word_new = ""
        for x in alphabets:
            word_new += x
        if word_new.isalpha():
            word_new += "ay"

        words_new.append(word_new)

    result = " ".join(words_new)
    return result


from unittest import TestCase

class TestPigIt(TestCase):
    def test_pig_it(test):
        test.assertEqual(pig_it('Pig latin is cool'), 'igPay atinlay siay oolcay')
        test.assertEqual(pig_it('This is my string'), 'hisTay siay ymay tringsay')