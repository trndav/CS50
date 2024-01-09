import csv

# file = open(".csv", "r")
# Or

# file = open(".csv")
# close(file)
# Or for automatic closing

# Iterate CSV
# with open("testcsv.csv") as file:
#     read = csv.reader(file) 
#     next(read) # Skip first line
#     for roworline in read:
#         print(roworline[1])
# OR

# Iterate with header connected to data - DictReader
# with open("testcsv.csv") as file:
#     read = csv.DictReader(file) # Anlyzes header - first line (each row is dictionary)
#     for roworline in read:
#         print(roworline["email"]) # From csv header 

# Count languages / item in row
# with open("testcsv.csv") as file:
#     read = csv.DictReader(file) # Anlyzes header - first line (each row is dictionary)
#     python = 0
#     c = 0
#     for roworline in read:
#         counteritem = roworline["language"] # From csv header 
#         if counteritem == "Python":
#             python += 1
#         elif counteritem == "C":
#             c += 1
# print(f"Python count: {python}")
# print(f"C count: {c}")

# Counting/iterating with dictionary count instead of 3 variables
# with open("testcsv.csv") as file:
#     read = csv.DictReader(file) # Anlyzes header - first line (each row is dictionary)
#     count = {} # Empty dictionary
#     for roworline in read:
#         counteritem = roworline["language"]
#         if counteritem in count:
#             count[counteritem] += 1
#         else:
#             count[counteritem] = 1
# # for counteritem in count:
# #     print(f"{counteritem}: {count[counteritem]}")

# # To sort output by value + reversed (highest first)
# for counteritem in sorted(count, key=count.get, reverse=True):
#     print(f"{counteritem}: {count[counteritem]}")

# Using Counter() to count row items
from collections import Counter
with open("testcsv.csv") as file:
    read = csv.DictReader(file) # Anlyzes header - first line (each row is dictionary)
    count = Counter()
    for roworline in read:
        counteritem = roworline["language"]
        count[counteritem] += 1

# Shorter with collections - Counter
for counteritem, count in count.most_common():
    print(f"{counteritem}: {count}")