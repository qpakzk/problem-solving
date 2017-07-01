

from random import randint, choice, shuffle
import string
def password_gen():
    _CHARSET = [string.ascii_lowercase, string.ascii_uppercase, string.digits]

    pw = [choice(charset) for charset in _CHARSET] + [choice(choice(_CHARSET)) for x in range(randint(3, 17))]
    shuffle(pw)

    return "".join(pw)

print(password_gen())

