def pig_it(text):
    return ' '.join([word[1:] + word[0] + 'ay' if word.isalpha() else word for word in text.split()])

from unittest import TestCase

class TestPigIt(TestCase):
    def test_pig_it(test):
        test.assertEqual(pig_it('Pig latin is cool'), 'igPay atinlay siay oolcay')
        test.assertEqual(pig_it('This is my string'), 'hisTay siay ymay tringsay')