from string import digits
from itertools import product

# This will print listo of numbers up to 9999
for passcode in product(digits, repeat=4):
    print(passcode)