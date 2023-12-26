# Start with python 68greet.py argument1 argumenttwo andsoon

from sys import argv

# if len(argv) == 2:
#     print(f"Hello, {argv[1]}")
# else:
#     print("Hello world!")

# for i in range(len(argv)):
#     print(argv[i] + " ", end="")

# for arg in argv:
#     print(arg, " ", end="")

for arg in argv[1:]:
    print(arg, " ", end="")