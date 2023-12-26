import sys

names = ["Charlie", "Ron", "Fred", "George"]

name = input("Enter name: ")
# for n in names:
#     if name == n:
#         print(f"Name {n} is found.")
#         sys.exit(0)
# Or
if name in names:
    print(f"Name {name} is found.")
    sys.exit(0)

print("Name is not found")
sys.exit(1)