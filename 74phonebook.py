import csv

# file = open("phonebook.csv", "a") # Open file and append to it
# name = input("Type name: ")
# number = input("Type number: ")
# writer = csv.writer(file)
# writer.writerow([name, number])
# file.close()

# Or with auto close file
# with open("phonebook.csv", "a") as file:
#     name = input("Type name: ")
#     number = input("Type number: ")
#     writer = csv.writer(file)
#     writer.writerow([name, number])

# With DictWriter, more precise as order is irrelevant
with open("phonebook.csv", "a", newline="") as file: # newline removes empty line
    name = input("Type name: ")
    number = input("Type number: ")
    writer = csv.DictWriter(file, fieldnames=["name", "number"])
    writer.writerow({"name": name, "number": number})