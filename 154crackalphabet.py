from string import ascii_letters
from itertools import product

# Print alphabet combinations up to 4 characters
for passcode in product(ascii_letters, repeat=4):
    print(passcode)