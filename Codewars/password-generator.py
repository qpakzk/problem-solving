"""
You need to write a password generator that meets the following criteria:

6 - 20 characters long
contains at least one lowercase letter
contains at least one uppercase letter
contains at least one number
contains only alphanumeric characters (no special characters)
Return the random password as a string.

Note: "randomness" is checked by counting the characters used in the generated passwords
 - all characters should have less than 50% occurance.
 Based on extensive tests, the normal rate is around 35%.
"""

import string, random

def password_gen():
    size = random.randint(6, 20)
    chars = string.ascii_uppercase + string.ascii_lowercase + string.digits

    password = "".join(random.choice(chars) for i in range(size))

    while password.islower() or password.isupper() or password.isdigit() or password.isalpha():
        password = "".join(random.choice(chars) for i in range(size))
    return password

print(password_gen())
